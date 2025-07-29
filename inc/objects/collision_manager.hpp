#ifndef OBJECTS_COLLISION_MANAGER_HPP
#define OBJECTS_COLLISION_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <utility>
#include <cmath>

#include "objects/object_base.hpp"

namespace simphys {
namespace sim {

class CollisionManager
{
    struct CellCoord {
        int x, y, z;
        bool operator==(const CellCoord& o) const noexcept {
            return x==o.x && y==o.y && z==o.z;
        }
    };

    struct CellHash {
        std::size_t operator()(const CellCoord& c) const noexcept {
            std::size_t h1 = std::hash<int>()(c.x);
            std::size_t h2 = std::hash<int>()(c.y);
            std::size_t h3 = std::hash<int>()(c.z);
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

    double cell_size_;
    std::vector<ObjectBase*> objects_;
    std::unordered_map<CellCoord, std::vector<ObjectBase*>, CellHash> grid_;

    CellCoord CellForPoint(const math::Point& p) const noexcept {
        return CellCoord{static_cast<int>(std::floor(p.x()/cell_size_)),
                         static_cast<int>(std::floor(p.y()/cell_size_)),
                         static_cast<int>(std::floor(p.z()/cell_size_))};
    }

public:
    explicit CollisionManager(double cell_size) : cell_size_(cell_size) {}

    void AddObject(ObjectBase* obj) { objects_.push_back(obj); }
    void ClearObjects() { objects_.clear(); }

    std::vector<std::pair<ObjectBase*, ObjectBase*>> DetectCollisions()
    {
        grid_.clear();
        for(auto* obj : objects_)
        {
            auto cell = CellForPoint(obj->BoundingSphere().Position());
            grid_[cell].push_back(obj);
        }

        std::vector<std::pair<ObjectBase*, ObjectBase*>> collisions;
        for(auto& [cell, objs] : grid_)
        {
            for(std::size_t i=0;i<objs.size();++i)
                for(std::size_t j=i+1;j<objs.size();++j)
                {
                    const auto& a = objs[i]->BoundingSphere();
                    const auto& b = objs[j]->BoundingSphere();
                    const auto centre_dist = (a.Position() - b.Position()).mag();
                    if(centre_dist <= (a.Radius()+b.Radius()))
                    {
                        if(objs[i]->ColidesWith(*objs[j]))
                            collisions.emplace_back(objs[i], objs[j]);
                    }
                }
        }
        return collisions;
    }
};

} // namespace sim
} // namespace simphys

#endif // OBJECTS_COLLISION_MANAGER_HPP

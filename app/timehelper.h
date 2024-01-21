#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include <chrono>
#include <type_traits>

using Time = std::chrono::high_resolution_clock;
using milliseconds = std::chrono::milliseconds;
using microseconds = std::chrono::microseconds;

class TimeHelper
{
    Time::time_point last_frame_time_;

    auto GetCurrentTime();
public:
    TimeHelper();
    void Init();
    double GetDt();
};

#endif // TIMEHELPER_H

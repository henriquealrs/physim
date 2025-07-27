# SymoPhysics

SymoPhysics is a small C++17 physics simulation library. It implements basic
particle dynamics, force generators and utilities used in simple physics
experiments.  Sample OpenGL applications demonstrate projectiles and
spring-based motion while unit tests verify the math and physics components.

## Building with CMake

The project uses CMake. A typical build will compile the library, the sample
applications and the unit test executable.

```bash
mkdir build
cd build
cmake ..
make
```

### Running Unit Tests

Google Test is fetched automatically during the CMake configure step. After the
build finishes you can run the tests with `ctest` or by executing the
`unit_tests` binary directly:

```bash
ctest           # runs all tests
./unit_tests    # same as above
```

### Launching Sample Applications

The build produces two example programs, `Balistics` and
`BalisticsWithSprings`. Run them from the build directory:

```bash
./Balistics
./BalisticsWithSprings
```

## Dependencies

- **CMake** 3.14 or newer
- **C++17 compiler** (e.g. GCC or Clang)
- **OpenGL** libraries (`GL`, `GLU` and `glut`) to build and run the sample apps
- **Google Test** for unit tests (downloaded automatically by CMake)



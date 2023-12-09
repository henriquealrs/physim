cmake_minimum_required(VERSION 3.14)

project(SymoPhysics)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC src/*.cpp )
file(GLOB_RECURSE HDR inc/*.hpp )

message("HDR: ${HDR}")

add_library(SymoPhysics ${SRC} ${HDR})

target_include_directories(SymoPhysics  PUBLIC "./inc")

# Set gtest
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()
add_subdirectory(unit_tests)
enable_testing()

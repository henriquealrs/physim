message("INCLUDE TESTS")

file(GLOB_RECURSE TEST_SRC ./*.cpp )

message("======= TEST ======")
message("Source: ${SRC}")
Message("Headers: ${HDR}")

add_executable(unit_tests ${TEST_SRC} ${SRC} ${HDR})

target_include_directories(unit_tests  PUBLIC "../inc")
target_link_libraries(unit_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)

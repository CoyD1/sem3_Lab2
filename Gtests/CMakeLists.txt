include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(googletest)

add_executable(GTestTests ${CMAKE_CURRENT_SOURCE_DIR}/IPTests.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../Tasks/IpTask.cpp)

target_include_directories(GTestTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Tasks)

target_link_libraries(GTestTests PRIVATE gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(GTestTests)
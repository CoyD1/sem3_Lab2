cmake_minimum_required(VERSION 3.31.6)
project(LAB2 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Gtests)

set(CPACK_PACKAGE_NAME "LAB2")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ivan Obuhov <vanushabrend@gmail.com>")
endif()

include(CPack)

add_executable(LAB2 main.cpp Tasks/IpTask.cpp)

install(TARGETS LAB2 DESTINATION bin)
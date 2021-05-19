project(QtJieba LANGUAGES CXX)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (UNIX)
    if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        set(CMAKE_INSTALL_PREFIX "/usr/local/cppjieba" CACHE PATH "default install path" FORCE)
    endif ()
    add_definitions(-O3 -Wall -g)
endif ()

if (APPLE) # mac os
    add_definitions(-std=c++0x)
endif ()

option(BUILD_TEST "Build unit test" OFF)
if (BUILD_TEST)
    enable_testing()
    add_subdirectory(deps)
    add_subdirectory(test)
    add_test(NAME ./test/test.run COMMAND ./test/test.run)
    add_test(NAME ./load_test COMMAND ./load_test)
    add_test(NAME ./demo COMMAND ./demo)
endif ()
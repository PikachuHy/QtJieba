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
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core
        REQUIRED)
add_library(QtJieba SHARED Tokenizer.cpp)
target_compile_definitions(QtJieba PRIVATE -DQtJieba_LIBRARY)
target_compile_definitions(QtJieba PRIVATE -D_CRT_SECURE_NO_WARNINGS)
target_link_libraries(QtJieba PUBLIC Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(QtJieba PRIVATE include deps
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_LIST_DIR})
    if (ANDROID)
        message(STATUS "andorid abi ${CMAKE_ANDROID_ARCH_ABI}")
        set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/android-build/libs/${CMAKE_ANDROID_ARCH_ABI}/)
        set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/android-build/libs/${CMAKE_ANDROID_ARCH_ABI}/)
    endif ()
qt_add_executable(QtJiebaMain
        MANUAL_FINALIZATION
        main.cpp
        )
qt_finalize_executable(QtJiebaMain)
target_link_libraries(QtJiebaMain PRIVATE QtJieba)
endif()

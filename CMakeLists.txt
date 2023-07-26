cmake_minimum_required(VERSION 3.27)

project(sma VERSION 0.0.1)

set(ENABLE_TESTS OFF CACHE BOOL "" FORCE)
if (ENABLE_TESTS) 
    include(FetchContent)
    FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.13.0
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    set(BUILD_GTEST ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    enable_testing()
endif()

add_subdirectory(lib)
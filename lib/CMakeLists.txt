set(LIB_SRC
    src/sma.cpp
)

add_library(sma-lib STATIC ${LIB_SRC})
target_compile_features(sma-lib PUBLIC cxx_std_17)
target_include_directories(sma-lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>)

if(ENABLE_TESTS)
    set(TEST_SRCS 
        tests/sma.cpp
    )
    add_executable(sma-tests ${TEST_SRCS})
    target_link_libraries(sma-tests PRIVATE sma-lib gtest gtest_main)

    include(GoogleTest)
    gtest_discover_tests(sma-tests)

endif()

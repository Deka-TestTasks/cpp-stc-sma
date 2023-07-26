set(LIB_SRC
    src/sma.cpp
)

add_library(sma-lib STATIC ${LIB_SRC})
target_compile_features(sma-lib PUBLIC cxx_std_17)
target_include_directories(sma-lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>)

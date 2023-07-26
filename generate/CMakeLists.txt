
set(APP_SRCS 
    src/main.cpp
)

add_executable(generate ${APP_SRCS})
target_link_libraries(generate sma-lib)


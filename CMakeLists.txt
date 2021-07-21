CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(BAES)

include_directories(include)

aux_source_directory(src AES_SRC)

add_library(AES_LIB ${AES_SRC})

add_executable(AES test/main.c)

target_link_libraries(AES AES_LIB)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O2")
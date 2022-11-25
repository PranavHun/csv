cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 99)

project(CSV)

add_library(csv STATIC csv.c csv.h)

add_executable(csv_runner csv_runner.c)
target_link_libraries(csv_runner csv)
if(MSVC)
target_compile_definitions(csv PRIVATE _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(csv_runner PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

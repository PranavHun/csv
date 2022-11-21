cmake_minimum_required(VERSION 3.0)

project(CSV)

add_library(csv STATIC csv.c csv.h)

add_executable(csv_runner csv_runner.c)
target_link_libraries(csv_runner csv)
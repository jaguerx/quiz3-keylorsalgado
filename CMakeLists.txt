cmake_minimum_required(VERSION 3.10)
project(Quiz3_Sensor_Update)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sensor_update main.c)

if(CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(sensor_update PRIVATE -Wall -Wextra -pedantic)
endif()
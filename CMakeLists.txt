cmake_minimum_required(VERSION 3.17)
project(MOPSI)
set(CMAKE_CXX_STANDARD 14)
add_executable(MOPSI main.cpp Data.cpp Data.h Global_Data.cpp Global_Data.h tools.cpp tools.h)
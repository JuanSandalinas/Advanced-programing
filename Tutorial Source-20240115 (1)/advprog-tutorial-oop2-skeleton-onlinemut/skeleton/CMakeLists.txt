cmake_minimum_required(VERSION 3.5)
project(OnlineMUT VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_COMPILER "g++")
add_executable(onlinemut main.cpp Student.cpp StudentCard.cpp Course.cpp Curriculum.cpp Lecture.cpp Practical.cpp)

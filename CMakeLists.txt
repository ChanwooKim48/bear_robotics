cmake_minimum_required(VERSION 3.10.0)
project(ATM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ATM
src/atm_controller.cpp 
src/database.cpp 
src/userdata.cpp 
src/main.cpp)
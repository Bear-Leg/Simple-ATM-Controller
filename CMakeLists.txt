cmake_minimum_required(VERSION 3.19)
project(ATM_Controller)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATM_Controller 
main.cpp
include/system.cpp include/system.h
include/account.cpp include/account.h
include/user.cpp include/user.h)

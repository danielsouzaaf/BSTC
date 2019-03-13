cmake_minimum_required(VERSION 3.13)
project(BSTC)

set(CMAKE_CXX_STANDARD 14)

add_executable(BSTC main.cpp BTree.cpp BTree.h)
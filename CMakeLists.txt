cmake_minimum_required(VERSION 3.20)
project(avltree)

set(CMAKE_CXX_STANDARD 14)

add_executable(avltree main.cpp AVLTree.cpp AVLTree.h test.cpp)

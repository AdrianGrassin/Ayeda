cmake_minimum_required(VERSION 3.22)
project(balancedtree)

set(CMAKE_CXX_STANDARD 14)

add_executable(balancedtree src/main.cpp include/binaryNode.h include/binarytree.h include/eqBT.h)

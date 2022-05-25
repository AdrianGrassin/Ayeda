cmake_minimum_required(VERSION 3.21)
project(balancedtree)

set(CMAKE_CXX_STANDARD 14)

add_executable(balancedtree src/main.cpp src/utilities.cpp include/binaryNode.h include/binarytree.h include/eqBT.h include/ABB.h include/utilities.h)

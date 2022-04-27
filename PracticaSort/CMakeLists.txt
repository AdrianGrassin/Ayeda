cmake_minimum_required(VERSION 3.22)
project(PracticaSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(PracticaSort src/main.cpp include/HeapSort.h include/P_orden.h include/key.h include/SeleccionSort.h include/QuickSort.h include/ShellSort.h include/RadixSort.h)

cmake_minimum_required(VERSION 3.27)
project(study)

set(CMAKE_CXX_STANDARD 17)

add_executable(study
        main.cpp
        carl/array.h
        carl/list.h
        carl/hash.h
        carl/string.h
        carl/stacksAndQueues.h
        carl/binaryTree.h
)
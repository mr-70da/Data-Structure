cmake_minimum_required(VERSION 3.27)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(QuickSort)
include_directories(SingleLinkedList)

add_executable(Data_Structure
        SingleLinkedList/SingleLinkedLIst.cpp
        SingleLinkedList/SingleLinkedLIst.h
        main.cpp
        CircularLinkedList/CirculerlinkedList.cpp
        DoublyLinkedList/DoublyLinkedList.cpp
)

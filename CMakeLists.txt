cmake_minimum_required(VERSION 3.21)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp MenuFW/MenuFW.cpp MenuFW/MenuFW.h Base/LinkedList/LinkedList.inl Base/LinkedList/LinkedList.h Exceptions/Exceptions.cpp Exceptions/Exceptions.h Graph/Graph.inl Graph/Graph.h UniqueId/UniqueId.h)

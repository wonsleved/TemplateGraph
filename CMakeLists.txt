cmake_minimum_required(VERSION 3.21)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp MenuFW/MenuFW.cpp MenuFW/MenuFW.h Base/LinkedList/LinkedList.inl Base/LinkedList/LinkedList.h Exceptions/Exceptions.cpp Exceptions/Exceptions.h GraphBase/Graph.inl GraphBase/Graph.h UniqueId/UniqueId.h CoordinateGraph/Point.h CoordinateGraph/CoordinateGrpah.cpp CoordinateGraph/CoordinateGrpah.h GraphBase/Functions/GraphFunctions.inl GraphBase/Functions/GraphFunctions.h Service/GraphService.h Menu/Menu.cpp Menu/Menu.h Random/Random.cpp Random/Random.h Tests/Tests.cpp Tests/Tests.h)

target_link_libraries(lab3 m)
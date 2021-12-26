#include <iostream>

#include "GraphBase/Graph.h"

#include "CoordinateGraph/CoordinateGrpah.h"
#include "GraphBase/Functions/GraphFunctions.h"

int main() {
try {
    Graph<int, int> graph;

    graph.addVertex(1).addVertex(2).addVertex(3).addVertex(4).addVertex(5).addVertex(6);
    graph.addEdge(1, 4, 111);
    graph.addEdge(1, 5, 111);
    graph.addEdge(1, 6, 111);
    graph.addEdge(1, 2, 111);
    graph.addEdge(2, 3, 111);


    int a = 1, b = 3;

    bool ok = bfs(graph, a, b);

    std::cout << ok;













//    CoordinateGraph graph;
//
//    Point one(1, 34);
//    Point two(22, 7);
//    Point three(33, 3);
//
//    graph.addPoint(one).addPoint(two).addPoint(three).addPoint(Point(1, 11));
//    graph.connectPoints(one, two);
//    graph.connectPoints(two, three);
//    graph.connectPoints(three, two);
//    graph.connectPoints(three, one);
//
//    std::cout << graph << std::endl;
//    graph.removePoint(three);
//
//    std::cout << graph;



} catch (std::exception& ex) {
    std::cout << ex.what();
}
    return 0;
}

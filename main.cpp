#include <iostream>

#include "GraphBase/Graph.h"

#include "CoordinateGraph/CoordinateGrpah.h"
#include "GraphBase/Functions/GraphFunctions.h"

int main() {
try {
    Graph<std::string, int> graph;

    graph.addVertex("one").addVertex("two").addVertex("three").addVertex("four").addVertex("five").addVertex("six").addVertex("seven").addVertex("eight");
    graph.addEdge("one", "two", 111);
    graph.addEdge("two", "three", 111);
    graph.addEdge("three", "four", 111);
    graph.addEdge("three", "six", 111);
    graph.addEdge("three", "seven", 111);
    graph.addEdge("three", "eight", 111);
    graph.addEdge("eight", "five", 111);
    graph.addEdge("one", "five", 111111);


    std::string a = "one", b = "five";

    bool ok = bfs(graph, a, b);

    std::vector<std::string> path;

    int dis = dijkstra(graph, a, b, path);

    printPath<std::string>(path);

    std::cout << std::endl;
    std::cout << dis;


    std::map<int, int> sptSet;












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

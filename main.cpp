#include <iostream>

#include "Graph/Graph.h"


int main() {

//    LinkedList<std::string> list;
//
//    list.append("kek");
//    list.append("lol");
//
//    for (const auto& i : list)
//        std::cout << i << std::endl;
try {
    Graph<int, int> graph;

    graph.getVertexCount();

    graph.addVertex(2).addVertex(3).addVertex(4);
    graph.addEdge(2, 3, 10);
    graph.addEdge(3, 4, 10);
    graph.addEdge(4, 3, 10);
    graph.addEdge(4, 2, 11);

    std::cout << graph << std::endl;

    graph.removeVertex(4);

    std::cout << graph;



} catch (std::exception& ex) {
    std::cout << ex.what();
}
    return 0;
}

#include <iostream>

#include "Graph/Graph.h"


int main() {

    Graph<int, int> graph;

    graph.addVertex(2).addVertex(5).addVertex(3);

    graph.containsVertex(2);

    return 0;
}

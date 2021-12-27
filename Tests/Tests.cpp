#include "Tests.h"


void mainTest(int count) {
    Graph<int, int> graph;

    std::cout << "Adding Vertices..." << std::endl;
    for (int i = 0; i < count; ++i) {
        graph.addVertex(i);
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Adding Edges..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            graph.addEdge(i, j, i + j);
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing containVertex..." << std::endl;
    for (int i = 0; i < count; ++i) {
        assert(graph.containsVertex(i));
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing containEdge..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            assert(graph.containsEdge(i ,j));
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing getEdgeData..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            assert(graph.getEdgeData(i ,j) == i + j);
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing BFS..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            assert(bfs(graph, i, j));
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing Dijkstra..." << std::endl;
    std::vector<int> path;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            assert(dijkstra(graph, i, j, path));
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Removing Edges..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            graph.removeEdge(i ,j);
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Testing containEdge..." << std::endl;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i == j)
                continue;
            assert(!graph.containsEdge(i ,j));
        }
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;


    std::cout << "Removing Vertices..." << std::endl;
    for (int i = 0; i < count; ++i) {
        graph.removeVertex(i );
    }
    std::cout << "[ " << count << " / " << count << " ]" << std::endl;

}
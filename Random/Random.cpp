#include "Random.h"

std::string randomString()
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 6);
}

int randomInteger(int min, int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);

    return uni(rng);
}

double randomDouble(double min, double max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> unif(min, max);
    return unif(rng);
}

void strIntRandGraph(Graph<std::string, int>& graph, int count) {
    for (int i = 0; i < count; ++i) {
        try {
            graph.addVertex(randomString());
        } catch (std::exception& exception) {}
    }


    for (auto& vert : graph.getAdjacencyList())
        for (auto& innerVert : graph.getAdjacencyList())
            if (vert.id != innerVert.id && randomInteger(0, 10) % 3)
                try {
                    graph.addEdge(vert.data, innerVert.data, randomInteger(0, 100));
                } catch (std::exception& exception) {}

}

void strDblRandGraph(Graph<std::string, double>& graph, int count) {
    for (int i = 0; i < count; ++i) {
        try {
            graph.addVertex(randomString());
        } catch (std::exception& exception) {}
    }

    for (auto& vert : graph.getAdjacencyList())
        for (auto& innerVert : graph.getAdjacencyList())
            if (vert.id != innerVert.id && randomInteger(0, 10) % 3)
                try {
                    graph.addEdge(vert.data, innerVert.data, randomDouble(0, 100));
                } catch (std::exception& exception) {}
}

void pointerRandGraph(Graph<Point, double>& graph, int count) {
    for (int i = 0; i < count; ++i) {
        try {
            graph.addVertex(Point(
                    randomInteger(-100, 100),
                    randomInteger(-100, 100)));
        } catch (std::exception& exception) {}
    }


    for (auto& vert : graph.getAdjacencyList())
        for (auto& innerVert : graph.getAdjacencyList())
            if (vert.id != innerVert.id && randomInteger(0, 10) % 3)
                try {
                    graph.addEdge(vert.data, innerVert.data, randomDouble(0, 100));
                } catch (std::exception& exception) {}
}
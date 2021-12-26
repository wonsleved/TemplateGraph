#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H
#include <iostream>
#include <exception>

#include "../Base/LinkedList/LinkedList.h"
#include "../UniqueId/UniqueId.h"


template <typename EdgeT, typename VertT>
class Graph {
private:
    struct Edge {
        EdgeT data;
        ID orientedTo;
    };

    struct Vertex {
        ID id;
        VertT data;
        LinkedList<Edge> connections;
    };

    LinkedList<Vertex> adjacencyList;

private:

    using GraphT = Graph<EdgeT, VertT>;

public:
    Graph() = default;
    Graph(const GraphT& graph);

    GraphT& addVertex(const VertT& data);
    GraphT& addVertex(const VertT&& data);

    GraphT& addEdge(const VertT& from, const VertT& to, const EdgeT& data);
    GraphT& addEdge(const VertT& from, const VertT& to, const EdgeT&& data);


    bool containsVertex(const VertT& data);
    bool existsEdge(const VertT& from, const VertT& to);

private:
    ID getVertexId(const VertT& data);
    Vertex& getVertexById(ID id);

};



#include "Graph.inl"

#endif

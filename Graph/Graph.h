#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H
#include <iostream>
#include <exception>

#include "../Base/LinkedList/LinkedList.h"
#include "../UniqueId/UniqueId.h"


template <typename VertT, typename EdgeT>
class Graph {
private:
    struct Edge {
        EdgeT data;
        ID orientedTo;
        Edge& operator = (const Edge& other) {
            orientedTo = other.orientedTo;
            data = other.data;
            return *this;
        }
    };

    struct Vertex {
        ID id;
        VertT data;
        LinkedList<Edge> connections;
        Vertex& operator = (const Vertex& other) {
            id = other.id;
            data = other.data;
            connections = other.connections;
            return *this;
        }
    };

    LinkedList<Vertex> adjacencyList;

private:

    using GraphT = Graph<VertT, EdgeT>;

public:
    Graph() = default;
    Graph(const GraphT& graph);

    int getVertexCount();
    int getEdgeCount(const VertT& data);
    int getEdgeCount(const VertT&& data);

    GraphT& addVertex(const VertT& data);
    GraphT& addVertex(const VertT&& data);

    GraphT& removeVertex(const VertT& data);
    GraphT& removeVertex(const VertT&& data);

    GraphT& addEdge(const VertT& from, const VertT& to, const EdgeT& data);
    GraphT& addEdge(const VertT& from, const VertT& to, const EdgeT&& data);

    GraphT& removeEdge(const VertT& from, const VertT& to);

    EdgeT getEdgeData(const VertT& from, const VertT& to);

    bool containsVertex(const VertT& data);
    bool containsEdge(const VertT& from, const VertT& to);


    Graph& operator = (const GraphT& other);
    bool operator == (const GraphT& other) const;

private:
    ID getVertexId(const VertT& data);
    Vertex& getVertexById(ID id);

};



#include "Graph.inl"

#endif

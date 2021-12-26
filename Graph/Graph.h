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

        friend std::ostream& operator<< (std::ostream &out, const Edge& edge) {
            out << "[ ";

            out << "id: " << edge.orientedTo << "; ";
            out << "data: " << edge.data;

            out << " ]";
            return out;
        }

        bool operator == (const Edge& other) const {
            return data == other.data && orientedTo == other.orientedTo;
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
        bool operator == (const Vertex& other) const {
            return data == other.data &&
                    id == other.id;
        }

        friend std::ostream& operator<< (std::ostream &out, const Vertex& vertex) {
            out << "[ ";
            out << "id: " << vertex.id << "; ";
            out << "data: " << vertex.data << "; ";
            out << "connections: " << vertex.connections;
            out << " ]";
            return out;
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

    friend std::ostream& operator<< (std::ostream &out, GraphT& graph) {
        for (auto& item : graph.adjacencyList)
            out << item << "\n";
        return out;
    }

private:
    ID getVertexId(const VertT& data);
    Vertex& getVertexById(ID id);

};



#include "Graph.inl"

#endif

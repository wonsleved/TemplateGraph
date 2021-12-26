#ifndef LAB3_GRAPHFUNCTIONS_H
#define LAB3_GRAPHFUNCTIONS_H

#include "../Graph.h"
#include <queue>
#include <map>

template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to, std::map<ID, ID>& parent);

template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to);

template <typename VertT, typename EdgeT>
ID minDistance(Graph<VertT, EdgeT> graph, std::map<ID, EdgeT>& dist, std::map<ID, bool> sptSet)
{
    auto adjacencyList = graph.getAdjacencyList();
    EdgeT min = -1;
    bool isMin = true;
    ID minIndex = -1;
    bool flag = true;



    for (auto& vert : adjacencyList) {


        if (!sptSet.contains(vert.id) && dist.contains(vert.id) && dist.find(vert.id)->second >= 0 &&
                (isMin || dist.find(vert.id)->second <= min)) {
            min = dist.find(vert.id)->second;
            minIndex = vert.id;
            flag = false;
            if (isMin)
                isMin = false;
        }
    }

    if (flag) {
        for (auto& vert : adjacencyList) {
            if (!sptSet.contains(vert.id) && dist.contains(vert.id) && dist.find(vert.id)->second < 0) {
                minIndex = vert.id;
                flag = false;
            }
        }
    }

    return minIndex;
}

template <typename VertT, typename EdgeT>
void fillPath(Graph<VertT, EdgeT> graph, std::map<ID, ID>& parent, ID id, std::vector<VertT>& path) {
    if (parent.find(id)->second == id) {
        path.push_back(graph.getVertexById(id).data);
        std::reverse(path.begin(), path.end());
        return;
    }

    fillPath(graph, parent, parent.find(id)->second, path);

    path.push_back(graph.getVertexById(id).data);
}

template <typename VertT>
void printPath(std::vector<VertT>& path) {
    for (int i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i + 1 != path.size())
            std::cout << " -> ";
    }
}

template <typename VertT, typename EdgeT>
EdgeT dijkstra(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to, std::vector<VertT>& path)
{
    ID fromId = graph.getVertexId(from);
    ID toId = graph.getVertexId(to);

    std::map<ID, ID> parent;

    parent[fromId] = fromId;

    int size = graph.getVertexCount();

    std::map<ID, EdgeT> dist;

    std::map<ID, bool> sptSet;

    dist[fromId] = 0;


    for (int count = 0; count < size; count++) {

        ID u = minDistance(graph, dist, sptSet);

        if (u + 1 == 0)
            continue;

        auto& uVert = graph.getVertexById(u);

        sptSet[u] = true;

        for (auto& vert : graph.getAdjacencyList()) {

            if (graph.containsEdge(uVert.data, vert.data) && dist.contains(u)) {

                auto weight = graph.getEdgeData(uVert.data, vert.data);

                if (!dist.contains(vert.id) || dist[u] + weight < dist.find(vert.id)->second) {

                    parent[vert.id] = u;

                    dist[vert.id] = dist.find(u)->second + weight;
                }
            }

        }
    }

    fillPath(graph, parent, toId, path);

    double distance = dist.find(toId)->second;
    return distance;
}



#include "GraphFunctions.inl"

#endif

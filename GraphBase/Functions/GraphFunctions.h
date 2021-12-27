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
ID minDistance(Graph<VertT, EdgeT> graph, std::map<ID, EdgeT>& dist, std::map<ID, bool> sptSet);

template <typename VertT, typename EdgeT>
void fillPath(Graph<VertT, EdgeT> graph, std::map<ID, ID>& parent, ID id, std::vector<VertT>& path);

template <typename VertT>
void printPath(std::vector<VertT>& path);

template <typename VertT, typename EdgeT>
EdgeT dijkstra(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to, std::vector<VertT>& path);

#include "GraphFunctions.inl"

#endif

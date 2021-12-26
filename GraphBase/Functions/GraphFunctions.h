#ifndef LAB3_GRAPHFUNCTIONS_H
#define LAB3_GRAPHFUNCTIONS_H

#include "../Graph.h"
#include <queue>
#include <map>

template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to, std::map<ID, ID>& parent);

template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to);


#include "GraphFunctions.inl"

#endif

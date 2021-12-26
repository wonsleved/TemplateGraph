


template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to, std::map<ID, ID>& parent) {

    ID vertexID = graph.getVertexId(from);
    ID toFindID = graph.getVertexId(to);
    std::queue<ID> queue;

    std::map<ID, bool> visited;

    visited[vertexID] = true;
    parent[vertexID] = vertexID;
    queue.push(vertexID);


    while (!queue.empty()) {

        ID currentVertexId = queue.back();

        queue.pop();

        auto& vert = graph.getVertexById(currentVertexId);

        for (auto &edge: vert.connections) {

            ID connectedId = edge.orientedTo;


            if (!visited.contains(connectedId)) {

                parent[connectedId] = currentVertexId;

                if (connectedId == toFindID)
                    return true;

                visited[connectedId] = true;
                queue.push(connectedId);
            }

        }
    }

    return false;
}

template <typename VertT, typename EdgeT>
bool bfs(Graph<VertT, EdgeT>& graph, VertT& from, VertT& to) {

    ID vertexID = graph.getVertexId(from);
    ID toFindID = graph.getVertexId(to);
    std::queue<ID> queue;

    std::map<ID, bool> visited;

    visited[vertexID] = true;
    queue.push(vertexID);


    while (!queue.empty()) {

        ID currentVertexId = queue.back();

        queue.pop();

        auto& vert = graph.getVertexById(currentVertexId);

        for (auto &edge: vert.connections) {

            ID connectedId = edge.orientedTo;

            if (!visited.contains(connectedId)) {

                if (connectedId == toFindID)
                    return true;

                visited[connectedId] = true;
                queue.push(connectedId);
            }

        }
    }

    return false;
}
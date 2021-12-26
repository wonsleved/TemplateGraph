template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>::
Graph(const GraphT &graph) {
    adjacencyList = graph.adjacencyList;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addVertex(const VertT& data) {
    if (containsVertex(data))
        throw std::runtime_error("Vertex already exists");

    ID id = getNewId();

    Vertex vertex;
    vertex.data = data;
    vertex.id = id;

    adjacencyList.append(vertex);
    return *this;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addVertex(const VertT&& data) {
    return addVertex(data);
}

template <typename VertT, typename EdgeT>
ID
Graph<VertT, EdgeT>::
getVertexId(const VertT& data) {
    ID id = -1;
    for (auto item : adjacencyList)
        if (item == data)
            id = item.id;

    if (id == -1)
        throw std::runtime_error("No vertex with such data!");

    return id;
}

template <typename VertT, typename EdgeT>
typename Graph<VertT, EdgeT>::Vertex&
Graph<VertT, EdgeT>::
getVertexById(ID id) {
    Vertex* vert;
    for (auto item : adjacencyList)
        if (item.id == id)
            vert = &item;

    if (id == -1)
        throw std::runtime_error("No item with this id!");

    return *vert;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addEdge(const VertT &from, const VertT &to, const EdgeT &data) try {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    Vertex& vertex = getVertexById(idFrom);

    bool alreadyExists = false;

    for (EdgeT& i : vertex.connections)
        if (i.orientedTo == idTo) {
            alreadyExists = true;
            i.data = data;
            break;
        }

    if (!alreadyExists) {
        Edge edge {idTo, data};

        vertex.connections.append(edge);
    }

    return *this;

} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addEdge(const VertT& from, const VertT& to, const EdgeT&& data) try {
    return addEdge(from, to, data);
} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
bool
Graph<VertT, EdgeT>::
containsVertex(const VertT& data) {
    bool doContains = false;

    for (Vertex& vert : adjacencyList)
        if (vert.data == data) {
            doContains = true;
            break;
        }

    return doContains;
}

template <typename VertT, typename EdgeT>
bool
Graph<VertT, EdgeT>::
containsEdge(const VertT& from, const VertT& to) try {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    bool exists = false;

    Vertex& vertex = getVertexById(idFrom);

    for (Edge& edge : vertex.connections)
        if (edge.orientedTo == idTo) {
            exists = true;
            break;
        }

    return exists;

} catch(std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
EdgeT
Graph<VertT, EdgeT>::
getEdgeData(const VertT& from, const VertT& to) try {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    Vertex& vertex = getVertexById(idFrom);

    EdgeT* pData;
    bool exists = false;

    for (Edge& edge : vertex.connections)
        if (edge.orientedTo == idTo) {
            pData = &edge.data;
            exists = true;
            break;
        }

    if (!exists)
        throw std::runtime_error("Edge doesn't exist!");

    return *pData;
} catch(std::exception& exception) {
    throw exception;
}
template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeEdge(const VertT& from, const VertT& to) try {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    Vertex& vertex = getVertexById(idFrom);

    bool exists = false;

    for (Edge& edge : vertex.connections)
        if (edge.orientedTo == idTo) {
            vertex.connections.removeItem(edge);
            exists = true;
            break;
        }

    if (!exists)
        throw std::runtime_error("Edge doesn't exist!");

    return *this;

} catch(std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeVertex(const VertT& data) try {
    ID vertexId = getVertexId(data);
    Vertex& vertex = getVertexById(vertexId);

    for (Vertex& vert : adjacencyList)
        if (containsEdge(vert.id, vertexId))
            removeEdge(vert.id, vertexId);

    adjacencyList.removeItem(vertex);

    return *this;

} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeVertex(const VertT&& data) try {
    return removeVertex(data);
} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
int
Graph<VertT, EdgeT>::
getVertexCount() {
    return adjacencyList.getSize();
}

template <typename VertT, typename EdgeT>
int
Graph<VertT, EdgeT>::
getEdgeCount(const VertT& data) try {
    ID id = getVertexId(data);
    Vertex& vertex = getVertexById(id);

    return vertex.connections.getSize();

} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
int
Graph<VertT, EdgeT>::
getEdgeCount(const VertT&& data) try {
    return getEdgeCount(data);
} catch (std::exception& exception) {
    throw exception;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
operator = (const GraphT& other) {
    if (*this == other)
        return *this;

    adjacencyList = other.adjacencyList;
    return *this;
}

template <typename VertT, typename EdgeT>
bool
Graph<VertT, EdgeT>::
operator == (const GraphT& other) const {
    return adjacencyList == other.adjacencyList;
}
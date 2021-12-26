template <typename EdgeT, typename VertT>
Graph<EdgeT, VertT>::
Graph(const GraphT &graph) {
    adjacencyList = graph.adjacencyList;
}

template <typename EdgeT, typename VertT>
Graph<EdgeT, VertT>&
Graph<EdgeT, VertT>::
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

template <typename EdgeT, typename VertT>
Graph<EdgeT, VertT>&
Graph<EdgeT, VertT>::
addVertex(const VertT&& data) {
    return addVertex(data);
}

template <typename EdgeT, typename VertT>
ID
Graph<EdgeT, VertT>::
getVertexId(const VertT& data) {
    ID id = -1;
    for (auto item : adjacencyList)
        if (item == data)
            id = item.id;

    if (id == -1)
        throw std::runtime_error("No vertex with such data!");

    return id;
}

template <typename EdgeT, typename VertT>
typename Graph<EdgeT, VertT>::Vertex&
Graph<EdgeT, VertT>::
getVertexById(ID id) {
    Vertex* vert;
    for (auto item : adjacencyList)
        if (item.id == id)
            vert = &item;

    if (id == -1)
        throw std::runtime_error("No item with this id!");

    return *vert;
}

template <typename EdgeT, typename VertT>
Graph<EdgeT, VertT>&
Graph<EdgeT, VertT>::
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

template <typename EdgeT, typename VertT>
Graph<EdgeT, VertT>&
Graph<EdgeT, VertT>::
addEdge(const VertT& from, const VertT& to, const EdgeT&& data) try {
    return addEdge(from, to, data);
} catch (std::exception& exception) {
    throw exception;
}

template <typename EdgeT, typename VertT>
bool
Graph<EdgeT, VertT>::
containsVertex(const VertT& data) {
    bool doContains = false;

    for (Vertex& vert : adjacencyList)
        if (vert.data == data) {
            doContains = true;
            break;
        }

    return doContains;
}

template <typename EdgeT, typename VertT>
bool
Graph<EdgeT, VertT>::
existsEdge(const VertT& from, const VertT& to) try {
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
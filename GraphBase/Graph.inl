template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>::
Graph(const GraphT &graph) {
    adjacencyList = graph.adjacencyList;
}
template <typename VertT, typename EdgeT>
LinkedList<typename Graph<VertT, EdgeT>::Vertex>
Graph<VertT, EdgeT>::
getAdjacencyList() {
    return adjacencyList;
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
    vertex.connections = LinkedList<Edge>();

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
        if (item.data == data)
            id = item.id;

    if (id == -1)
        throw std::runtime_error("No vertex with such data!");

    return id;
}

template <typename VertT, typename EdgeT>
typename Graph<VertT, EdgeT>::Vertex&
Graph<VertT, EdgeT>::
getVertexById(ID id) {
    Vertex* vert = nullptr;
    for (auto& item : adjacencyList)
        if (item.id == id)
            vert = &item;

    if (!vert)
        throw std::runtime_error("No item with this id!");

    return *vert;
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addEdge(const VertT &from, const VertT &to, const EdgeT &data) {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    Vertex& vertex = getVertexById(idFrom);

    bool alreadyExists = false;

    for (Edge& item : vertex.connections)
        if (item.orientedTo == idTo) {
            alreadyExists = true;
            item.data = data;
            break;
        }

    if (!alreadyExists) {
        Edge edge = {data, idTo};
        vertex.connections.append(edge);
    }

    return *this;

}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
addEdge(const VertT& from, const VertT& to, const EdgeT&& data) {
    return addEdge(from, to, data);
}

template <typename VertT, typename EdgeT>
bool
Graph<VertT, EdgeT>::
containsVertex(const VertT& data) {


    bool doContains = false;

    for (const Vertex& vert : adjacencyList) {
        if (vert.data == data) {
            doContains = true;
            break;
        }
    }

    return doContains;
}

template <typename VertT, typename EdgeT>
bool
Graph<VertT, EdgeT>::
containsEdge(const VertT& from, const VertT& to) {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);

    bool exists = false;

    Vertex& vertex = getVertexById(idFrom);

    LinkedList<Edge>& edges = vertex.connections;

    for (Edge& edge : edges) {
        if (edge.orientedTo == idTo) {
            exists = true;
            break;
        }
    }

    return exists;

}

template <typename VertT, typename EdgeT>
EdgeT
Graph<VertT, EdgeT>::
getEdgeData(const VertT& from, const VertT& to) {
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
}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeEdge(const VertT& from, const VertT& to) {
    ID idFrom = getVertexId(from);
    ID idTo = getVertexId(to);


    Vertex& vertex = getVertexById(idFrom);

    bool exists = false;

    LinkedList<Edge>& edges = vertex.connections;

    for (Edge& edge : edges)
        if (edge.orientedTo == idTo) {
            vertex.connections.removeItem(edge);
            exists = true;
            break;
        }

    if (!exists)
        throw std::runtime_error("Edge doesn't exist!");

    return *this;

}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeVertex(const VertT& data) {
    ID vertexId = getVertexId(data);
    Vertex& vertex = getVertexById(vertexId);

    for (Vertex& vert : adjacencyList) {
        if (containsEdge(vert.data, vertex.data))
            removeEdge(vert.data, vertex.data);
    }



    adjacencyList.removeItem(vertex);

    return *this;

}

template <typename VertT, typename EdgeT>
Graph<VertT, EdgeT>&
Graph<VertT, EdgeT>::
removeVertex(const VertT&& data) {
    return removeVertex(data);
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
getEdgeCount(const VertT& data) {
    ID id = getVertexId(data);
    Vertex& vertex = getVertexById(id);

    return vertex.connections.getSize();

}

template <typename VertT, typename EdgeT>
int
Graph<VertT, EdgeT>::
getEdgeCount(const VertT&& data) {
    return getEdgeCount(data);
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


//template <typename U, typename V>
//std::ostream& operator << (std::ostream &out, GraphBase<U, V> graph) {
//    for (auto& item : graph.adjacencyList)
//        out << item << "\n";
//    return out;
//}


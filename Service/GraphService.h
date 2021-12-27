#ifndef LAB3_GRAPHSERVICE_H
#define LAB3_GRAPHSERVICE_H

#include "../GraphBase/Graph.h"
#include "../GraphBase/Functions/GraphFunctions.h"

template<typename VertT, typename EdgeT>
class GraphService {
private:
    using GraphT = Graph<VertT, EdgeT>;
    GraphT* graph;

public:
    explicit GraphService(GraphT& graphT) {
        graph = &graphT;
    }

    GraphService(GraphService<VertT, EdgeT>& graphService) = default;

    ~GraphService() {
        delete graph;
    }


    void addVertex(const VertT& data) try {
        graph->addVertex(data);
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void addEdge(const VertT& from, const VertT& to, const EdgeT& data) try {
        graph->addEdge(from, to, data);
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void removeVertex(const VertT& data) try {
        graph->removeVertex(data);
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void removeEdge(const VertT& from, const VertT& to) try {
        graph->removeEdge(from, to);
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void outputWeight(const VertT& from, const VertT& to) try {
        std::cout << graph->getEdgeData(from, to) << std::endl;
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void outputGraph() try {
        if (graph->getVertexCount())
            std::cout << *graph;
        else
            std::cout << "Graph is empty" << std::endl;
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void outputShortestPathLength(VertT& from, VertT& to) try {
        if (bfs(*graph, from, to)) {
            std::vector<VertT> path;
            std::cout << dijkstra(*graph, from, to, path) << std::endl;
        } else {
            std::cout << "Impossible to reach " << to << " from " << from << std::endl;
        }
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    void outputShortestPath(VertT& from, VertT& to) try {
        if (bfs<VertT, EdgeT>((Graph<VertT, EdgeT>&)*graph, from, to)) {
            std::vector<VertT> path;
            dijkstra(*graph, from, to, path);
            printPath(path);
            std::cout << std::endl;
        } else {
            std::cout << "Impossible to reach " << to << " from " << from;
        }
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    GraphT* getGraph() {
        return graph;
    }

    GraphService& operator = (const GraphService&graphService) {
        if (this != &graphService)
            graph = graphService.graph;
        return *this;
    }
};



#endif

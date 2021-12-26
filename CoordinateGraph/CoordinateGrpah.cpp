#include "CoordinateGrpah.h"




CoordinateGraph::CoordinateGraph(const CoordinateGraph& cGraph) {
    graph = cGraph.graph;
}

int CoordinateGraph::getPointsCount() {
    return graph.getVertexCount();
}

int CoordinateGraph::getConnectionsCount(const Point& point) {
    return graph.getEdgeCount(point);
}

int CoordinateGraph::getConnectionsCount(const Point&& point) {
    return graph.getEdgeCount(point);
}

CoordinateGraph& CoordinateGraph::addPoint(const Point& point) {
    graph.addVertex(point);
    return *this;
}

CoordinateGraph& CoordinateGraph::addPoint(const Point&& point) {
    return addPoint(point);
}

CoordinateGraph& CoordinateGraph::removePoint(const Point& point) {
    graph.removeVertex(point);
    return *this;
}

CoordinateGraph& CoordinateGraph::removePoint(const Point&& point) {
    return removePoint(point);
}

CoordinateGraph& CoordinateGraph::connectPoints(const Point& from, const Point& to) {
    graph.addEdge(from, to, calculateDistance(from, to));
    return *this;
}

CoordinateGraph& CoordinateGraph::connectPoints(const Point&& from, const Point&& to) {
    return connectPoints(from, to);
}

CoordinateGraph& CoordinateGraph::removeConnection(const Point& from, const Point& to) {
    graph.removeEdge(from, to);
    return *this;
}

CoordinateGraph& CoordinateGraph::removeConnection(const Point&& from, const Point&& to) {
    return removeConnection(from, to);
}

double CoordinateGraph::getDistance(const Point& from, const Point& to) {
    return graph.getEdgeData(from, to);
}

bool CoordinateGraph::containsPoint(const Point& point) {
    return graph.containsVertex(point);
}

bool CoordinateGraph::areConnected(const Point& from, const Point& to) {
    return graph.containsEdge(from, to);
}




double CoordinateGraph::calculateDistance(const Point& point1, const Point& point2) {
    double xDistance = point1.x - point2.x;
    double yDistance = point1.y - point2.y;

    return sqrt(xDistance * xDistance + yDistance * yDistance);
}




std::ostream& operator << (std::ostream &out, CoordinateGraph& cGraph) {
    out << cGraph.graph;
    return out;
}

bool CoordinateGraph::operator == (const CoordinateGraph& other) const {
    return graph == other.graph;
}

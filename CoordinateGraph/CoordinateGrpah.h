#ifndef LAB3_COORDINATEGRPAH_H
#define LAB3_COORDINATEGRPAH_H

#include "../GraphBase/Graph.h"
#include "Point.h"

class CoordinateGraph {
private:
    Graph<Point, double> graph;
public:
    CoordinateGraph() = default;
    CoordinateGraph(const CoordinateGraph& cGraph);

    int getPointsCount();
    int getConnectionsCount(const Point& point);
    int getConnectionsCount(const Point&& point);

    CoordinateGraph& addPoint(const Point& point);
    CoordinateGraph& addPoint(const Point&& point);

    CoordinateGraph& removePoint(const Point& point);
    CoordinateGraph& removePoint(const Point&& point);

    CoordinateGraph& connectPoints(const Point& from, const Point& to);
    CoordinateGraph& connectPoints(const Point&& from, const Point&& to);

    CoordinateGraph& removeConnection(const Point& from, const Point& to);
    CoordinateGraph& removeConnection(const Point&& from, const Point&& to);

    double getDistance(const Point& from, const Point& to);

    bool containsPoint(const Point& point);
    bool areConnected(const Point& from, const Point& to);


    CoordinateGraph& operator = (const CoordinateGraph& other) = default;

    bool operator == (const CoordinateGraph& other) const;

    friend std::ostream& operator << (std::ostream &out, CoordinateGraph& cGraph);

private:

    double calculateDistance(const Point& point1, const Point& point2);

};


#endif

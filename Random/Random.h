#ifndef LAB3_RANDOM_H
#define LAB3_RANDOM_H

#include <iostream>
#include <random>

#include "../GraphBase/Graph.h"
#include "../CoordinateGraph/CoordinateGrpah.h"

std::string randomString();
int randomInteger(int min, int max);
double randomDouble(double min, double max);

void strIntRandGraph(Graph<std::string, int>& graph, int count);
void strDblRandGraph(Graph<std::string, double>& graph, int count);
void pointerRandGraph(Graph<Point, double>& graph, int count);

#endif

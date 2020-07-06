#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <limits.h>

int* dijkstra_routes(graph_t *g, int start);

const int G_INF = INT_MAX;

#endif
#ifndef GRAPH_H
#define GRAPH_H

struct graph;
typedef struct graph graph_t;

graph_t *g_create(int n, int def);
int g_change_vertex(graph_t *g, int n, int m, int v);
int g_get_vertex(graph_t *g, int n, int m);
int g_get_size(graph_t *g);

#endif
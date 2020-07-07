#ifndef GRAPH_H
#define GRAPH_H

struct graph;
typedef struct graph graph_t;

graph_t *g_create(int n, int def);
void g_destroy(graph_t *g);
int g_set_weight(graph_t *g, int i, int j, int v);
int g_get_weight(graph_t *g, int i, int j);
int g_get_size(graph_t *g);

#endif
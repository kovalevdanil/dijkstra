#include "graph.h"
#include <malloc.h>

struct graph
{
    int n;
    int **vert;
};

graph_t *g_create(int n, int def)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->vert = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        graph->vert[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            graph->vert[i][j] = def;
    }

    return graph;
}

int g_set_vertex(graph_t *g, int i, int j, int v)
{
    if (i < 0 || j < 0 || i >= g->n || j >= g->n)
        return -1;

    g->vert[i][j] = v;

    return 0;
}

int g_get_vertex(graph_t *g, int i, int j)
{
    if (i < 0 || j < 0 || i >= g->n || j >= g->n)
        return -1;
    
    return g -> vert[i][j];
}
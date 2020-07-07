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

    graph->vert = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        graph->vert[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            graph->vert[i][j] = def;
    }

    graph -> n = n;

    return graph;
}

void g_destroy(graph_t *g)
{
    if (g == NULL)
        return;

    int n = g -> n;

    for (int i = 0; i < n; i++)
        free(g -> vert[i]);
    free(g -> vert);
    free(g);
}

int g_set_weight(graph_t *g, int i, int j, int v)
{
    if (g == NULL || i < 0 || j < 0 || i >= g->n || j >= g->n)
        return -1;

    (g->vert)[i][j] = v;

    return 0;
}

int g_get_weight(graph_t *g, int i, int j)
{
    if (g == NULL || i < 0 || j < 0 || i >= g->n || j >= g->n)
        return -1;
    
    return g -> vert[i][j];
}

int g_get_size(graph_t *g)
{
    return g == NULL ? -1 : g -> n;
}
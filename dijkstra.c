#include "dijkstra.h"
#include <malloc.h>
#include <stdint.h>

int *dijkstra_routes(graph_t *g, int start)
{
    int size = g_get_size(g);

    if (start < 0 || start >= size)
        return NULL;

    int *routes = malloc(size * sizeof(int));
    uint8_t *labels = calloc(size, sizeof(uint8_t));

    for (int i = 0; i < size; i++)
        routes[i] = G_INF;
    routes[start] = 0;

    int current_vertex = start, 
        arc_weight = 0,
        min_weight = G_INF,
        min_vertex;

    for (int i = 0; i < size; i++)
    {
        labels[current_vertex] = 1;
        min_weight = G_INF;


        for (int j = 0; j < size; j++)
        {
            arc_weight = g_get_vertex(g, current_vertex, j);
            if (labels[j] == 1 || arc_weight == 0)
                continue;

            if (routes[j] == G_INF || arc_weight + routes[current_vertex] < routes[j])
                routes[j] = arc_weight + routes[current_vertex];
            
            if (routes[j] < min_weight)
            {
                min_weight = routes[j];
                min_vertex = j;
            }
        }

        if (min_weight == G_INF)
            break;

        current_vertex = min_vertex;
    }

    free(labels);

    return routes;
}
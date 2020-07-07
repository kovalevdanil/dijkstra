#include <stdio.h>
#include <malloc.h>
#include "dijkstra.h"

int main()
{
    int n, arc_count, v1, v2, weight;
    scanf("%d", &n);
    
    graph_t *graph = g_create(n, 0);
    scanf("%d", &arc_count);

    for (int i = 0; i < arc_count; i++)
    {
        scanf("%d %d %d", &v1, &v2, &weight);
        int ret = g_set_weight(graph, v1, v2, weight);

        if (ret == -1)
        {
            fprintf(stderr, "Error has occured\n");
            return -1;
        }
    }

    int start;
    scanf("%d", &start);

    int *routes = dijkstra_routes(graph, start);

    for (int i = 0; i < n; i++)
        printf("%d ", routes[i]);
    printf("\n");
    
    free(routes);

    return -1;
}

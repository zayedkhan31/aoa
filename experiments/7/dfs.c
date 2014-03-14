#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif
#include "set.c"
#include "queue.c"
#include "priority_queue.c"
#include "unionfind.c"
#include "graphM.c"

void depth_first_traversal(Graph *g, int vertex, Set *s_visited) {
    int i;
    if(set_exists(s_visited, vertex) > 0) {
        return;
    }
    set_add(s_visited, vertex);
    for(i = 0; i < g->size; i++) {
        if(i == vertex || !is_connected(g, vertex, i)) continue;
        depth_first_traversal(g, i, s_visited);
    }
    printf("Visiting %d\n", vertex);
}

void main() {
    int i, j, k1, k2, w, count;
    Set *s_visited;
    Graph *g = init_graph(10);
    for(i = 0; i < 10; i++) {
        k1 = (int) rand() % 10;
        k2 = (int) rand() % 10;
        w = (int) rand() % 100 + 1;
        add_edge(g, k1, k2, w);
    }
    graph_display(g);
    s_visited = set_create();
    printf("Depth first traveral\n***********************\n");
    depth_first_traversal(g, 0, s_visited);
}

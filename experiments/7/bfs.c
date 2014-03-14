#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif
#include "set.c"
#include "queue.c"
#include "graphM.c"

void breath_first_traversal(Graph *g, int vertex) {
    int i, j, k, u, v;
    datatype *d;
    Set *s_visited = set_create();
    Queue *q_unvisited = create_queue();
    d = (datatype *)malloc(sizeof(datatype));
    d->key = vertex;
    queue_add(q_unvisited, d); 
    free(d);
    while(queue_size(q_unvisited) > 0) {
        d = queue_remove(q_unvisited);
        if(d == NULL) 
            break;
        u = d->key;
        if(set_exists(s_visited, u) > 0)  continue;
        printf("Visiting %d\n", u);
        set_add(s_visited, u);
        for(i = 0; i < g->size; i++) {
            if(i == u || is_connected(g, u, i) == 0) 
                continue;
            d = (datatype *) malloc(sizeof(datatype));
            d->key = i;
            queue_add(q_unvisited, d); 
            free(d);
            d = NULL;
        }
    }
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
    printf("Breath first traveral\n***********************\n");
    breath_first_traversal(g, 0);
}

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


void mst_prim(Graph *g) {
    int i, j, k, count = 1, source, old_source;
    datatype *d;
    PQ *pq;
    UnionFind *uf;
    Set *visited, *unvisited, *edges;
    Queue *q_unvisited;
    printf("**************\nPrims MST\n**************\n");
    pq = create_PQ(10);
    uf = UF_create(g->vertex, g->size);
    visited = set_create(g->size);
    unvisited = set_create(g->size);
    for(i = 0; i < g->size; i++)
        set_add(unvisited, g->vertex[i]);
    source = 0;
    while(unvisited->root != NULL) {
        for(i = 0 ; i < g->size; i++) {
            if(g->edges[source][i] <= 0 || set_exists(visited, i)) 
                continue;
            d = (datatype *) malloc(sizeof(datatype));
            d->key = g->edges[source][i];
            d->v11 = source;
            d->v12 = i;
            d->v21 = i;
            d->v22 = source;
            offer(pq, d);
            free(d);
        }
        set_remove(unvisited, source);
        set_add(visited, source);
        if(is_empty(pq)) {
            break;
        }
        
        old_source = source;
        while(!is_empty(pq)){ 
            d = (datatype *) malloc(sizeof(datatype));
            count = take(pq, d);
            if(!count || (set_exists(visited, d->v11) && set_exists(visited, d->v12))) 
                continue;
            printf("Edge %d, %d [%d]\n", d->v11, d->v12, d->key);
            if(set_exists(visited, d->v11) && !(set_exists(visited, d->v12)) ) {
                source = d->v12;
                break;
            }
            else if(set_exists(visited, d->v12) && !(set_exists(visited, d->v11))) {
                source = d->v11;
                break;
            }
        }
        if(old_source == source) break;
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
    mst_prim(g);
}

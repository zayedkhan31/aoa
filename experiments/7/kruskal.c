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


void mst_krushkal(Graph *g) {
    int i, j, k, count = 1;
    PQ *pq;
    UnionFind *uf;
    datatype *d;
    pq = create_PQ(10);
    uf = UF_create(g->vertex, g->size);
    printf("**************\nKrushkals MST\n**************\n");
    
    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            //count = get_edge_keys(g, edge_keys, i, j);
            if(g->edges[i][j] > 0) {
                d = (datatype *) malloc(sizeof(datatype));
                d->key = g->edges[i][j];
                d->v11 = i;
                d->v12 = j;
                d->v21 = j;
                d->v22 = i;
                offer(pq, d);
                free(d);
            }
        }
    }

    while(!is_empty(pq)){
        d = (datatype *) malloc(sizeof(datatype));
        count = take(pq, d);

        if(uf_is_connected(uf, d->v11, d->v12)) continue;
        Union(uf, d->v11, d->v12);
        printf("Edge %d, %d [%d]\n", d->v11, d->v12, d->key);
        free(d);
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
    mst_krushkal(g);
}

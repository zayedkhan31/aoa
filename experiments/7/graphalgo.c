#include<stdio.h>
#include<stdlib.h>
#include "data.c"
#include "set.c"
#include "priority_queue.c"
#include "unionfind.c"
#include "graphM.c"

void depth_first_traversal(Graph *g, int vertex, Set *s_visited) {
    int i;
    if(set_exists(s_visited, vertex) > 0) {
        return;
    }
    set_add(s_visited, vertex, NULL);
    for(i = 0; i < g->size; i++) {
        if(i == vertex) continue;
        if(!is_connected(g, vertex, i)) continue;
        depth_first_traversal(g, i, s_visited);
    }
    printf("Visiting %d\n", vertex);
}

void breath_first_traversal(Graph *g, int vertex) {
    int i, j, k, u, v;
    Set *s_visited = set_create(10);
    Set *s_unvisited = set_create(10);
    set_add(s_unvisited, vertex, NULL);
    while(set_size(s_unvisited) > 0) {
        u = set_get(s_unvisited, 0);
        printf("Visiting %d\n", u);
        set_remove(s_unvisited, u);
        for(i = 0; i < g->size; i++) {
            if(i == u || is_connected(g, u, i) == 0 || set_exists(s_visited, i) > 0) 
                continue;
            set_add(s_unvisited, i, NULL);
        }
        set_add(s_visited, u, NULL);
    }
}

void init_edge_keys(Graph *g, int **edge_keys) {
    int i, j, k, count = 1;
    
    for(i = 0; i < g->size; i++) {
        for(j = 0; j < g->size; j++) {
            if(i == j) k = -1;
            else k = count;
            edge_keys[i][j] = k;
            edge_keys[j][i] = k;
            count++;
        }
    }
}

int get_edge_keys(Graph *g, int **edge_keys, int v1, int v2) {
    if(edge_keys == NULL) return 0;
    return edge_keys[v1][v2];
}

int get_edge_by_key(Graph *g, int **edge_keys, int key, int *a, int *b, int *c, int *d) {
    int i, j;
    if(edge_keys == NULL) return 0;
    for(i = 0; i < g->size; i++) {
        for(j = 0; j < g->size; j++) {
            if(edge_keys[i][j] == key) {
                *a = i; *b = j; *c = j; *d = i;
                return 1;
            }
        }
    }
    a = b = c = d = NULL;
    return 0;
}

void mst_prim(Graph *g) {
    int i, j, k, count = 1, data, v11, v12, v21, v22, **edge_keys, source, old_source;
    PQ *pq;
    UnionFind *uf;
    Set *visited, *unvisited, *edges;
    int NULL_DATA = 0, key;
    printf("**************\nPrims MST\n**************\n");
    pq = create_PQ(10);
    uf = UF_create(g->vertex, g->size);
    visited = set_create(g->size);
    unvisited = set_create(g->size);
    edge_keys = malloc(g->size * sizeof(int *));

    for(i = 0; i < g->size; i++) {
        edge_keys[i] = (int *) malloc(g->size * sizeof(int));
        set_add(unvisited, i, &NULL_DATA);
    }

    init_edge_keys(g, edge_keys);

    
    source = set_get_data(unvisited, 0)->key;
    while(set_size(unvisited) > 0) {
        for(i = 0 ; i < g->size; i++) {
            if(g->edges[source][i] <= 0 || set_exists(visited, i)) 
                continue;
            count = get_edge_keys(g, edge_keys, source, i);
            offer(pq, g->edges[source][i], count);
        }
        set_remove(unvisited, source);
        set_add(visited, source, &NULL_DATA);
        if(is_empty(pq)) break;
        
        old_source = source;
        while(!is_empty(pq)){ 
            data = take(pq, &key);
            if(!get_edge_by_key(g, edge_keys, key, &v11, &v12, &v21, &v22)
                || (set_exists(visited, v11) && set_exists(visited, v12))) 
                continue;
            printf("Edge %d, %d [%d]\n", v11, v12, data);
            if(set_exists(visited, v11) && !(set_exists(visited, v12)) ) {
                source = v12;
                break;
            }
            else if(set_exists(visited, v12) && !(set_exists(visited, v11))) {
                source = v11;
                break;
            }
        }
        if(old_source == source) break;
    }

}

void mst_krushkal(Graph *g) {
    int i, j, k, count = 1, data, v11, v12, v21, v22, **edge_keys;
    PQ *pq;
    UnionFind *uf;
    pq = create_PQ(10);
    uf = UF_create(g->vertex, g->size);
    printf("**************\nKrushkals MST\n**************\n");
    edge_keys = malloc(g->size * sizeof(int *));
    for(i = 0; i < g->size; i++) {
        edge_keys[i] = (int *) malloc(g->size * sizeof(int));
    }

    init_edge_keys(g, edge_keys);

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            count = get_edge_keys(g, edge_keys, i, j);
            if(g->edges[i][j] > 0)
                offer(pq, g->edges[i][j], count);
        }
    }

    while(!is_empty(pq)){
        count = take(pq, &data);

        if(get_edge_by_key(g, edge_keys, data, &v11, &v12, &v21, &v22)){
            if(uf_is_connected(uf, v11, v12)) continue;
            uf_connect(uf, v11, v12);
            printf("Edge %d, %d [%d]\n", v11, v12, count);
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
    mst_krushkal(g);
    mst_prim(g);
    /*
    s_visited = set_create(10);
    printf("Depth first traveral\n***********************\n");
    depth_first_traversal(g, 0, s_visited);
    printf("Breath first traveral\n***********************\n");
    breath_first_traversal(g, 0);
    */
    
}

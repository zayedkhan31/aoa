#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *vertex;
    int **edges;
    int size;
} Graph;


Graph *init_graph(int vertex_size);
void add_edge(Graph *g, int i, int j, int w);
int *get_vertexes(Graph *g);
int **get_edges(Graph *g);
void remove_edge(Graph *g, int i, int j);
int is_connected(Graph *g, int i, int j);


int is_connected(Graph *g, int i, int j){
    if (i >= g->size || j >= g->size) {
        return -1;
    }
    return g->edges[i][j] > 0;
}

Graph *init_graph(int vertex_size) {
    int i, j, w;
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->size = vertex_size;
    g->vertex = (int *) malloc(vertex_size * sizeof(int));
    g->edges = malloc(vertex_size * sizeof(int *));
    for(i = 0; i < g->size; i++) {
        g->vertex[i] = i;
        g->edges[i] = (int *) malloc(g->size * sizeof(int));
    }
    return g;
    for(i = 0; i < g->size ; i++) {
        for(j = i+1; j < g->size; j++) {
            if(j == i) continue;
            w = abs((int) ((rand() + 1) * (rand() - 1)/(rand() + 1) * (rand() - 1)) % 100);
            add_edge(g, i, j, w); 
        }
    }
    return g;
}

void graph_display(Graph *g) {
    int i, j;
    printf("    ");
    for(i = 0; i < g->size; i++)
        printf("%5d ", g->vertex[i]);
    printf("\n");
    for(i = 0; i < g->size*3; i++) 
        printf("__");
    printf("____");

    printf("\n");
    for(i = 0; i < g->size; i++) {
        printf("%d | ", g->vertex[i]);
        for(j = 0; j < g->size; j++) {
            printf("%5d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int *get_vertexes(Graph *g) { return g->vertex; }

int **get_edges(Graph *g) { return g->edges; }

void remove_edge(Graph *g, int i, int j) {
    add_edge(g, i, j, 0);
}
void add_edge(Graph *g, int i, int j, int w) {
    if (i >= g->size || j >= g->size) {
        printf("Unable to add edge, one of the vertex is non existent.\n");
        return;
    }
    g->edges[i][j] = w;
    g->edges[j][i] = w;
}

/*
void main() {
    int i, j;
    Graph *g;
    g = init_graph(10);
    graph_display(g);
    for(i = 0; i < g->size; i++) {
        for(j = i+1; j < g->size; j++) {
            if((int) rand() % 10 > 5) continue;
            add_edge(g, i, j, (int) rand() % 100);
        }
    }
    printf("\n");
    printf("\n");
    graph_display(g);
}
*/

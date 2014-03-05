#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *keys;
    int size;
} UnionFind;


UnionFind *UF_create(int *keys, int size) {
    int i;
    UnionFind *uf = (UnionFind *) malloc(sizeof(UnionFind));
    uf->keys = (int *) malloc(size * sizeof(int));
    uf->size = size;
    for(i = 0; i < size; i++) {
        uf->keys[i] = keys[i];
    }
    return uf;
}

void uf_connect(UnionFind *uf, int i, int j) {
    int k = 0;
    if (i >= uf->size || j >= uf->size) {
        printf("i and j out of bounds\n");
        return;
    }
    for(k = 0; k < uf->size; k++) {
        if (uf->keys[k] == uf->keys[j]) {
            uf->keys[k] = uf->keys[i];
        }
    }
}

int uf_is_connected(UnionFind *uf, int i, int j){
    if (i >= uf->size || j >= uf->size) {
        printf("i and j out of bounds\n");
        return -1;
    }
    return uf->keys[i] == uf->keys[j];
}

void uf_display(UnionFind *uf) {
    int i;
    for(i = 0; i < uf->size; i++) 
        printf("%d ", uf->keys[i]);
    printf("\n");
}

/*
void main() {
    UnionFind *uf;
    int i, j;
    int keys[] = {0, 1, 2, 3, 4, 5, 6};
    uf = UF_create(keys, 7);
    uf_display(uf);
    for(i = 0; i < uf->size; i++)
        for(j = 0; j < uf->size; j++) {
            if (i == j) continue;
            if((int) rand() % 10 < 7) continue;
            printf("Connecting %d %d,\t", i, j);
            uf_connect(uf, i, j);
            uf_display(uf);
        }
    for(i = 0; i < uf->size; i++)
        for(j = 0; j < uf->size; j++)
            printf("Connected: %d, %d = %d\n", i, j, uf_is_connected(uf, i, j));
}
*/

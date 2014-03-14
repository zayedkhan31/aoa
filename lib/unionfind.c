#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *keys;
    int *ranks;
    int size;
} UnionFind;


UnionFind *UF_create(int *keys, int size) {
    int i;
    UnionFind *uf = (UnionFind *) malloc(sizeof(UnionFind));
    uf->keys = (int *) malloc(size * sizeof(int));
    uf->ranks = (int *) malloc(size * sizeof(int));
    uf->size = size;
    for(i = 0; i < size; i++) {
        uf->keys[i] = keys[i];
        uf->ranks[i] = 0;
    }
    return uf;
}

int Find(UnionFind *uf, int i) {
    if (i >= uf->size) {
        printf("i is out of bounds\n");
        return -1;
    }
    if (uf->keys[i] != i)
        uf->keys[i] = Find(uf, uf->keys[i]);
    return uf->keys[i];
}

void Union(UnionFind *uf, int i, int j) {
    int i_root, j_root;
    i_root = Find(uf, i);
    j_root = Find(uf, j);
    if (i_root == j_root) return;

    if (uf->ranks[i_root] < uf->ranks[j_root])
        uf->keys[i_root] = j_root;
    else if (uf->ranks[i_root] > uf->ranks[j_root])
        uf->keys[j_root] = i_root;
    else {
        uf->keys[j_root] = i_root;
        uf->ranks[i_root] += 1;
    }

}

int uf_is_connected(UnionFind *uf, int i, int j){
    int i_root, j_root;
    i_root = Find(uf, i);
    j_root = Find(uf, j);
    return i_root == j_root;
}

void uf_display(UnionFind *uf) {
    int i;
    for(i = 0; i < uf->size; i++) 
        printf("%d:[%d, %d], ", i, uf->keys[i], uf->ranks[i]);
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
            Union(uf, i, j);
            uf_display(uf);
        }
    for(i = 0; i < uf->size; i++)
        for(j = 0; j < uf->size; j++)
            printf("Connected: %d, %d = %d\n", i, j, uf_is_connected(uf, i, j));
}
*/

#include<stdio.h>
#include<stdlib.h>
#include "heapsort.c"

#define SIZE 10000

typedef struct _pq {
    Heap *heap;
} PQ;

PQ *create_PQ(int length) {
    PQ *pq = (PQ *) malloc(sizeof(PQ));
    pq->heap = create_heap(length);
    return pq;
}

void offer(PQ *pq, int key, int data) {
    insert(pq->heap, key, data);
}

int take(PQ *pq, int *data) {
    return extract_min(pq->heap, data);
}

int is_empty(PQ *pq) {
    return pq->heap->heapsize <= 0;
}

/*
void main() {
    int i, j;
    int data;
    PQ *pq = create_PQ(10000);
    for(i = 0; i < 10000; i++) {
        j = (int) abs(rand() * 1) % 100;
        printf("Inserting %d\n", j);
        data = (int) rand() % 1000;
        offer(pq, j, data);
    }
    i = 0;
    while(!is_empty(pq)) {
        printf("%d: %d {%d}\n", i, take(pq, &data), data);
        i++;
    }
}
*/

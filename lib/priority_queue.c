#include<stdio.h>
#include<stdlib.h>
#include "heapsort.c"

typedef struct _pq {
    Heap *heap;
} PQ;

PQ *create_PQ(int length) {
    PQ *pq = (PQ *) malloc(sizeof(PQ));
    pq->heap = create_heap(length);
    return pq;
}

void offer(PQ *pq, datatype *data) {
    insert(pq->heap, data);
}

int take(PQ *pq, datatype *data) {
    return extract_min(pq->heap, data);
}

int is_empty(PQ *pq) {
    return pq->heap->heapsize <= 0;
}

/*
void main() {
    int i, j;
    PQ *pq = create_PQ(10000);
    int min;
    datatype *d;
    for(i = 0; i < 10000; i++) {
        j = (int) abs(rand() * 1) % 100;
        printf("Inserting %d\n", j);
        d = (datatype *) malloc(sizeof(datatype));
        d->key = j;
        d->data = (int) rand() % 1000;
        d->v11 = 11;
        d->v12 = 12;
        d->v21 = 21;
        d->v22 = 22;
        offer(pq, d);
        free(d);
    }
    i = 0;
    while(!is_empty(pq)) {
        d = (datatype *) malloc(sizeof(datatype));
        min = take(pq, d);
        printf("%d: %d {%d}\n", i, min, d->data);
        free(d);
        i++;
    }
}
*/

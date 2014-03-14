#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif

typedef struct _heap {
    datatype **nodes;
    int heapsize;
    int length;
} Heap;

Heap *create_heap(int length){
    Heap *heap = (Heap *) malloc(sizeof(Heap));  
    heap->nodes = malloc(length * sizeof(datatype *));
    heap->length = length;
    heap->heapsize = 0;
    return heap;
}

int parent(int i) {
    return (i - 1)/2 ;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(Heap *heap, int i, int j) {
    datatype *temp;
    temp = heap->nodes[i];
    heap->nodes[i] = heap->nodes[j];
    heap->nodes[j] = temp;
}

void min_heapify(Heap *heap, int i) {
    int l, r, value;
    l = left(i); r = right(i);
    if (l < heap->heapsize && heap->nodes[l]->key <= heap->nodes[i]->key) 
        value = l;
    else 
        value = i;
    if (r < heap->heapsize && heap->nodes[r]->key <= heap->nodes[value]->key) 
        value = r;
    if (value != i) {
        swap(heap, value, i);
        min_heapify(heap, value);
    }
}

void insert(Heap *heap, datatype *data) {
    int temp, j, i, len, size;
    datatype **nodes, *node;
    if (heap->length < (heap->heapsize + 1)){
        len = 2 * heap->length;
        nodes = malloc(len * sizeof(datatype *));
        for(j = 0; j < heap->heapsize; j++) {
            nodes[j] = heap->nodes[j];
        }
        free(heap->nodes);
        heap->nodes = nodes;
        heap->length = len;
    }
    node = (datatype *) malloc(sizeof(datatype));
    node->key = data->key;
    node->data = data->data;
    node->v11 = data->v11;
    node->v12 = data->v12;
    node->v21 = data->v21;
    node->v22 = data->v22;
    heap->nodes[heap->heapsize] = node;
    i = heap->heapsize;
    heap->heapsize++;
    while(i >= 0 && parent(i) != i) {
        if (heap->nodes[parent(i)]->key > heap->nodes[i]->key) {
            swap(heap, i, parent(i));
        }
        i = parent(i);
    }
}

int extract_min(Heap *heap, datatype *data) {
    int min, d;
    if(heap->heapsize <= 0) {
        printf("Heap empty\n");
        return 0;
    }
    min = heap->nodes[0]->key;
    data->key = heap->nodes[0]->key;
    data->data = heap->nodes[0]->data;
    data->v11 = heap->nodes[0]->v11;
    data->v12 = heap->nodes[0]->v12;
    data->v21 = heap->nodes[0]->v21;
    data->v22 = heap->nodes[0]->v22;
    heap->nodes[0] = heap->nodes[heap->heapsize - 1];
    heap->nodes[heap->heapsize - 1] = NULL;
    heap->heapsize--;
    min_heapify(heap, 0);
    return min;
}

void build_min_heap(Heap *heap) {
    int i;
    int len = heap->heapsize;
    for(i = len/2; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

void heapsort(Heap *heap) {
    int i;
    build_min_heap(heap);
    for(i = heap->heapsize / 2; i >= 0; i--){
        swap(heap, 0, i);
        min_heapify(heap, 0);
    }
}

void small_display(Heap *heap) {
    int i;
    printf("[");
    for(i = 0; i < heap->heapsize; i++) {
        if(i < heap->heapsize - 1)
            printf("%d, ", heap->nodes[i]->key);
        else
            printf("%d", heap->nodes[i]->key);
    }
    printf("]\n");
}

void display(Heap *heap) {
    int i;
    printf("Heap Max Size: %d\n", heap->length);
    printf("Heap Current Size: %d\n", heap->heapsize);
    printf("Heap Data: [");
    for(i = 0; i < heap->heapsize; i++) {
        if(i < heap->heapsize - 1)
            printf("%d, ", heap->nodes[i]->key);
        else
            printf("%d", heap->nodes[i]->key);
    }
    printf("]\n");
}

/*
void main() {
    int i, min;
    Heap *heap = create_heap(10);
    datatype *d;
    for(i = 0; i < 20; i++) {
        d = (datatype *) malloc(sizeof(datatype));
        d->key = 20 - i;
        d->data = 10;
        d->v11 = 11;
        d->v12 = 12;
        d->v21 = 21;
        d->v22 = 22;
        insert(heap, d);
        free(d);
    }
    small_display(heap); 
    //printf("Sorting again\n");
    //heapsort(heap);
    small_display(heap); 
    while(heap->heapsize > 0) {
        printf("Getting min\n");
        d = (datatype *) malloc(sizeof(datatype));
        min = extract_min(heap, d);
        printf("Min :%d {%d}\n", min, d->key);
        small_display(heap); 
        free(d);
    }
}
*/

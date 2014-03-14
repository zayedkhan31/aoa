#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif

#define QUEUE_SIZE 10000

typedef struct {
    datatype **nodes;
    int head;
    int tail;
    int length;
    int size;
} Queue;

Queue *create_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->nodes = malloc(QUEUE_SIZE * sizeof(datatype *));
    queue->length = QUEUE_SIZE;
    queue->head = 0;
    queue->tail = -1;
    queue->size = 0;
    return queue;
}

void queue_add(Queue *queue, datatype *data) {
    int temp, j, i, len, size, absolute_head;
    datatype **nodes, *node;
    
    node = (datatype *) malloc(sizeof(datatype));
    node->key = data->key;
    node->data = data->data;
    node->v11 = data->v11;
    node->v12 = data->v12;
    node->v21 = data->v21;
    node->v22 = data->v22;
    
    if (queue->head < queue->tail &&
            queue->size > 0 ) {
        printf("Queue is full\n"); 
        return;
    }
    if(queue->tail == -1) {
        queue->tail = 0;
    }
    queue->nodes[queue->head] = node;
    queue->head = (queue->head + 1) % queue->length;
    queue->size++;
}

datatype *queue_remove(Queue *queue) {
    int i;
    datatype * d;
    if(queue->size <= 0) {
        return NULL;
    }
    d = (datatype *)malloc(sizeof(datatype));
    d->key = queue->nodes[queue->tail]->key;
    d->data = queue->nodes[queue->tail]->data;
    d->v11 = queue->nodes[queue->tail]->v11;
    d->v12 = queue->nodes[queue->tail]->v12;
    d->v21 = queue->nodes[queue->tail]->v21;
    d->v22 = queue->nodes[queue->tail]->v22;
    free(queue->nodes[queue->tail]);
    queue->tail = (queue->tail + 1) % queue->length;
    queue->size--;
    return d;
}

int queue_size(Queue *queue) {
    return queue->size;
}

void queue_display(Queue *queue) {
    int i, absolute_head;
    if(queue->tail == -1 && queue->head == 0) {
        printf("Queue is empty\n");
    }
    printf("Queue data: ");
    for(i = queue->tail; i < queue->tail + queue->size; i++) {
        printf("%d ", queue->nodes[i % queue->length]->key);
    }
    printf("\n");
}

/*
void main() {
    int i;
    Queue *queue = create_queue();
    datatype *d;
    for(i = 0; i < 3; i++) {
        d = (datatype *) malloc(sizeof(datatype));
        d->key = i;
        d->data = 10;
        d->v11 = 11;
        d->v12 = 12;
        d->v21 = 21;
        d->v22 = 22;
        printf("Adding %d\n", d->key);
        queue_add(queue, d);
        free(d);
        queue_display(queue);
    }
    while(queue_size(queue) > 0) {
        d = queue_remove(queue);
        if(d == NULL) {
            printf("Not removed but size is there\n");
            continue;
        }
        printf("Removed %d\n", d->key);
        free(d);
    }
    for(i = 0; i < 3; i++) {
        d = (datatype *) malloc(sizeof(datatype));
        d->key = i;
        d->data = 10;
        d->v11 = 11;
        d->v12 = 12;
        d->v21 = 21;
        d->v22 = 22;
        printf("Adding %d\n", d->key);
        queue_add(queue, d);
        free(d);
        queue_display(queue);
        d = queue_remove(queue);
        if(d == NULL) {
            printf("Removed %d\n", d->key);
            free(d);
        }
    }
}
*/

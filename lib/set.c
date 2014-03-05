#include<stdio.h>
#include<stdlib.h>
/*#include "data.c"*/

typedef struct _set {
    datatype **data;
    int size;
    int length;
} Set;

Set *set_create(int size) {
    Set *s = (Set *) malloc(sizeof(Set));
    s->data = malloc(size * sizeof(datatype *));
    s->size = 0;
    s->length = size;
    return s;
}

void set_add(Set *s, int key, int *data) {
    int i, counter, found = 0;
    datatype **set_data, *d;
    for(i = 0; i < s->size; i++) {
        if (s->data[i]->key == key) 
            found = 1;
    }
    if (found) {
        return;
    }
    if(s->length <= s->size) {
        set_data =  malloc(s->length * 2 * sizeof(datatype *));
        for(i = 0; i < s->size; i++) {
            set_data[i] = s->data[i];
        }
        free(s->data);
        s->data = set_data;
        s->length = s->length * 2;
    }
    counter = s->size++; 
    d = (datatype *) malloc(sizeof(datatype));
    d->key = key;
    if(data != NULL)
        d->data = *data;
    else d->data = 0;
    s->data[counter] = d;
}

int set_get(Set *s, int position) {
    int i, found = 0;
    if(s->size <= position) return -1;
    return s->data[position]->key;
}

datatype *set_get_data(Set *s, int position) {
    int i, found = 0;
    if(s->size <= position) return NULL;
    return s->data[position];
}

int set_get_position(Set *s, int key) {
    int i, found = 0;
    for(i = 0; i < s->size; i++) {
        if (s->data[i]->key == key) {
            found = 1;
            break;
        }
    }
    if(found) return i;
    else return -1;
}

int set_exists(Set *s, int key) {
    if(set_get_position(s, key) != -1) return 1;
    else return 0;
}

void set_remove(Set *s, int key) {
    int i, position;
    position = set_get_position(s, key);
    if (position == -1) {
        return;
    }
    free(s->data[position]);
    for(i = position; i < s->size - 1; i++) {
        s->data[i] = s->data[i + 1];
    }
    s->size--;
}

void set_display(Set *s) {
    int i;
    printf("Set: ");
    for(i = 0; i < s->size; i++) printf("%d ", s->data[i]->key);
    printf("\n");
}

int set_size(Set *s) {
    return s->size;
}

/*
void main() {
    int i;
    Set *s = set_create(10);
    for(i = 0; i < 20; i++) {
        set_add(s, i % 10, NULL);
    }
    set_display(s);
    if(set_exists(s, 0) > 0) printf("Element 0 exists\n");
    else printf("Element 0 does not exists\n");
    if(set_exists(s, 20) > 0) printf("Element 20 exists\n");
    else printf("Element 20 does not exists\n");
    for(i = 0; i < 20; i++) {
        set_remove(s, i % 10);
    }
    set_display(s);
}
*/

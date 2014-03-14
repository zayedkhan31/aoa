#include<stdio.h>
#include<stdlib.h>
#include "tree.c"

typedef struct _set {
    Node *root;
} Set;

Set *set_create() {
    Set *s = (Set *) malloc(sizeof(Set));
    s->root = NULL; 
    return s;
}

void set_add(Set *s, int key) {
    int i, counter, found = 0;
    if(s->root == NULL) 
        s->root = create_node(key);
    else
        add(s->root, key);
}

int set_exists(Set *s, int key) {
    if(search(s->root, key) != NULL) return 1;
    else return 0;
}

void set_remove(Set *s, int key) {
    s->root = delete(s->root, key);
}

void set_display(Set *s) {
    print(s->root);
}

int set_empty(Set *s) {
    return s->root == NULL;
}

/*
void main() {
    int i, x;
    Set *s = set_create();
    for(i = 0; i < 20; i++) {
        set_add(s, (int) rand() % 10);
    }
    set_display(s);
    if(set_exists(s, 0) > 0) printf("Element 0 exists\n");
    else printf("Element 0 does not exists\n");
    if(set_exists(s, 20) > 0) printf("Element 20 exists\n");
    else printf("Element 20 does not exists\n");
    for(i = 0; i < 20; i++) {
        x = i % 10;
        printf("Removing %d\n", x);
        set_remove(s, x);
        set_display(s);
    }
    set_display(s);
}
*/

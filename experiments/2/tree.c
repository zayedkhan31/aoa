#include "data.c"

typedef struct binary_tree_node {
    datatype data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} Node;

Node *create_node(int value) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->data = value;
    return n;
}

Node *add(Node *root, int data) {
    if (root->data < data) {
        if(root->right == NULL) {
            root->right = create_node(data);
            return root->right;
        }
        return add(root->right, data);
    }
    else {
        if(root->left== NULL) {
            root->left= create_node(data);
            return root->left;
        }
        return add(root->left, data);
    }
}

Node *search(Node *root, int data) {
    if (root == NULL) {
        printf("Not found\n");
        return NULL;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    else if(root->data > data){
        return search(root->left, data);
    }
    else {
        return root;
    }
}

void preorder(Node  *root, Node *parent, int count) {
    int i;
    if(root==NULL) return;
    for(i = 0; i < 2 * count; i++) printf(" ");
    if (parent != NULL) {
        if (parent->left == root) printf("L: ");
        else printf("R: ");
    }
    printf("%d\n", root->data);
    preorder(root->left, root, count + 1);
    preorder(root->right, root, count + 1);
}

void print(Node *root) {
    int count = 0;
    preorder(root, NULL, count);
    printf("\n");
}

void clean(Node *node) {
    printf("Begin Cleaning...");
    node->left = NULL;
    node->right = NULL;
    free((void *) node);
    printf("End Cleaning...\n");
}

void destory(Node *root) {
    destory(root->left);
    destory(root->right);
    free((void *) root);
}

Node *delete(Node *root, int data) {
    Node *parent=NULL, *temp=NULL, *temp2=NULL, *node=NULL, *old_node=NULL;
    Node *previous=NULL;
    if (root== NULL) {
        printf("Tree is empty\n");
        return root;
    }

    temp = root;

    while(temp != NULL && temp->data != data) {
        temp2 = temp;
        if (temp->data > data) 
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (temp->data == data) {
        node = temp;
        parent = temp2;
    }
    else {
        printf("Not found, so no delete of %d\n", data);
        return root;
    }
    temp2 = NULL;
    old_node = node; 
    if (node->left == NULL && node->right == NULL) {
        node = NULL;
    }
    else if (node->left != NULL && node->right == NULL) {
        node = node->left;
    }
    else if (node->left == NULL && node->right != NULL) {
        node = node->right;
    }
    else {
        previous = node->left;
        temp = previous;
        temp2 = NULL;
        while(previous->right != NULL) {
            temp = previous;
            previous = previous->right;
        }
        printf("Previous [%d], Temp[%d], \n", previous->data, temp->data);
        if (temp != previous) {
            if(previous->left != NULL) {
                temp2 = previous->left;
            }
            else {
                temp2 = NULL;
            }
            if(temp->left == previous) temp->left = temp2;
            else temp->right = temp2;
            previous->left = node->left;
            previous->right = node->right;
        }
        else {
            previous->right = node->right;
        }
        node = previous;
        //printf("Node is previous now %d, [%d, %d]\n", node->data, node->left->data, node->right->data);
    }
    if (parent != NULL && parent != old_node) {
        if(parent->left == old_node)  {
            parent->left = node;
        }
         else {
            parent->right = node;
         }
    }
    else if (root == old_node) {
        root = node; 
    }
    else {
        printf("Yeah whatever\n");
    }
    clean(old_node);
    return root;
}

void main() {
    int i, val, count=0; 
    int arr[10], completed[10];
    Node *temp;
    Node *root = create_node(rand() % 1000);
    for(i = 0; i < 10; i++) {
        arr[i] = rand() % 1000;
    }
    for(i = 0; i < 10; i++) {
        add(root, arr[i]);
    }
    print(root);
    printf("\n");
    root = delete(root, root->data);
    print(root);
    i = 0;
    while(i < 10) {
        val = arr[i];
        root = delete(root, val);
        print(root);
        i++;
    }
    print(root);
}


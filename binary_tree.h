#ifndef BINARYTREE
#define BINARYTREE

typedef struct Node Node;

Node* bintree_create();
void bintree_insert(Node* root, int elem);
Node* bintree_search(Node* node, int elem);
void bintree_print_left_first(Node* node);
void bintree_print_right_first(Node* node);

#endif
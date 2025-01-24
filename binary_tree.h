#ifndef BINARYTREE
#define BINARYTREE

#include <stdbool.h>

typedef struct Node Node;

Node* bintree_create();
void bintree_insert(Node* root, int elem);
bool bintree_remove(Node* node, int elem);
Node* bintree_search(Node* node, int elem);
Node* bintree_min(Node* node);
Node* bintree_max(Node* node);
void bintree_print_left_first(Node* node);
void bintree_print_right_first(Node* node);
int bintree_value(Node* node);
Node* bintree_successor(Node* node);
Node* bintree_predecessor(Node* node);

#endif
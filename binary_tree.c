#include "binary_tree.h"
#include "tsdefs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node
{
	i32 elem;
	Node *left;
	Node *right;
	Node *parent;
} Node;

static bool is_empty = true;

Node* bintree_create()
{
	Node* node = malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	return node;
}

static inline bool is_leaf(Node *node)
{
	return !(node->right || node->left); 
}

void bintree_insert(Node* node, int elem)
{
	if (is_empty)
	{
		is_empty = false;
		node -> elem = elem;
	}
	else
	{
		Node* current_node = node;
		Node* parent = 0;

		while (current_node)
		{
			parent = current_node;
			if (elem < current_node->elem)
				current_node = current_node->left;
			else
				current_node = current_node->right;
		}

		printf("creating new node for elem %d\n", elem);
		current_node = malloc(sizeof(Node));
		memset(current_node, 0, sizeof(Node));
		current_node->elem = elem;
		current_node->parent = parent;

		if (elem < parent->elem)
			parent->left = current_node;
		else
			parent->right = current_node;
	}
}

Node* bintree_search(Node* node, int elem)
{
	if (!node || elem == node->elem) return node;
	if (elem < node->elem) 
		return bintree_search(node->left, elem);
	else
		return bintree_search(node->right, elem);
}

void bintree_print_left_first(Node* node)
{	
	if (node)
	{
		bintree_print_left_first(node->left);
		printf("%d\n", node->elem);
		bintree_print_left_first(node->right);
	}
}

void bintree_print_right_first(Node* node)
{	
	if (node)
	{
		bintree_print_right_first(node->right);
		printf("%d\n", node->elem);
		bintree_print_right_first(node->left);
	}
}

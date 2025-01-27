#include "binary_tree.h"
#include "tsdefs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

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

Node* bintree_insert(Node* node, int elem)
{
	if (is_empty)
	{
		is_empty = false;
		node -> elem = elem;
		return node;
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

		return current_node;
	}
}

bool bintree_remove(Node* node, int elem)
{
	Node* node_to_remove = bintree_search(node, elem);
	if (!node_to_remove) return false;

	//Node to remove have no children
	if (is_leaf(node_to_remove))
	{
		if (elem < node_to_remove->parent->elem)
		{
			node_to_remove->parent->left = 0;
		}
		else
		{
			node_to_remove->parent->right = 0;
		}
	}
	//Node to remove has just one child (right child)
	else if (!node_to_remove->left)
	{
		if (elem < node_to_remove->parent->elem)
		{
			node_to_remove->parent->left = node_to_remove->right;
			node_to_remove->right->parent = node_to_remove->parent;
		}
		else
		{
			node_to_remove->parent->right = node_to_remove->right;
			node_to_remove->right->parent = node_to_remove->parent;
		}
	}
	//Node to remove has just one child (left child)
	else if (!node_to_remove->right)
	{
		if (elem < node_to_remove->parent->elem)
		{
			node_to_remove->parent->left = node_to_remove->left;
			node_to_remove->left->parent = node_to_remove->parent;
		}
		else
		{
			node_to_remove->parent->right = node_to_remove->left;
			node_to_remove->left->parent = node_to_remove->parent;
		}
	}
	//Node to remove has two children
	else
	{
		Node* successor = bintree_successor(node_to_remove);
		/*if (!successor)
		{
			node->parent->right = 0;
			free(node);
		}*/
		if (successor == node_to_remove->right)
		{
			successor->parent = node_to_remove->parent;
			if (node->parent->right == node_to_remove) node_to_remove->parent->right = successor;
			else node_to_remove->parent->left = successor;
		}
		else
		{
			Node* right_child_successor = successor->right;
			successor->parent->left = right_child_successor;
			right_child_successor->parent = successor->parent;

			successor->parent = node_to_remove->parent;
			if (node_to_remove->parent->right == node_to_remove) node_to_remove->parent->right = successor;
			else node_to_remove->parent->left = successor;
			successor->right = node_to_remove->right;
			successor->left = node_to_remove->left;
		}
	}

	free(node_to_remove);

	return true;
}

//This function only updates where the parent of the old root points now and the parent of the new root
//It doesn't update the left/right children of old_root or new_root
void bintree_transplant(Node* old_root, Node *new_root)
{
	if (!old_root->parent)
		old_root = new_root;
	else if (old_root == old_root->parent->left)
		old_root->parent->left = new_root;
	else
		old_root->parent->right = new_root;

	if (!new_root) new_root->parent = old_root->parent;

}

Node* bintree_search(Node* node, int elem)
{
	if (!node || elem == node->elem) return node;
	if (elem < node->elem) 
		return bintree_search(node->left, elem);
	else
		return bintree_search(node->right, elem);
}

Node* bintree_min(Node* node)
{
	assert(!is_empty);

	Node* current_node = node;
	while (current_node->left)
	{
		current_node = current_node->left;
	}

	return current_node;
}

Node* bintree_max(Node* node)
{
	assert(!is_empty);

	Node* current_node = node;
	while (current_node->right)
	{
		current_node = current_node->right;
	}

	return current_node;
}

int bintree_value(Node* node)
{
	assert(!is_empty);
	return node->elem;
}

Node* bintree_successor(Node* node)
{
	assert(!is_empty);
	if (node->right) return bintree_min(node->right);

	//If there is no right subtree, then the successor is the
	//lowest ancestor whose left child is also ancestor	
	Node* ancestor = node->parent;
	while (ancestor && node == ancestor->right)
	{
		node = ancestor;
		ancestor = ancestor->parent;
	}

	return ancestor;
}

Node* bintree_predecessor(Node* node)
{
	assert(!is_empty);
	if (node->left) return bintree_max(node->left);

	//If there is no left subtree, then the predecessor is the
	//lowest ancestor whose right child is also ancestor
	Node* ancestor = node->parent;
	while (ancestor && node == ancestor->left)
	{
		node = ancestor;
		ancestor = ancestor->parent;
	}

	return ancestor;
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
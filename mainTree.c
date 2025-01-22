#include <stdio.h>
#include "binary_tree.h"

int main()
{
	Node* tree = bintree_create();
	bintree_insert(tree, 10);
	bintree_insert(tree, 5);
	bintree_insert(tree, 2);
	bintree_insert(tree, 20);

	//printf("Value of the root = %d\n", tree->elem)
	bintree_print_left_first(tree);
	printf("\n\n");
	bintree_print_right_first(tree);	
	return 0;
}
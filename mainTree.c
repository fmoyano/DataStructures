#include <stdio.h>
#include "binary_tree.h"

int main()
{
	Node* tree = bintree_create();
	bintree_insert(tree, 10);
	bintree_insert(tree, 5);
	bintree_insert(tree, 2);
	bintree_insert(tree, 20);

		// 10
	// 5       //20
// 2
	//printf("Value of the root = %d\n", tree->elem)
	bintree_print_left_first(tree);
	printf("\n\n");
	bintree_print_right_first(tree);

	bool res = bintree_remove(tree, 0);
	printf("Removed 0 from tree: %d\n", res);

	res = bintree_remove(tree, 5);
	printf("Removed 5 from tree: %d\n", res);

	res = bintree_remove(tree, 2);
	printf("Removed 2 from tree: %d\n", res);

	res = bintree_remove(tree, 20);
	printf("Removed 20 from tree: %d\n", res);

	bintree_print_left_first(tree);
	printf("\n\n");
	bintree_print_right_first(tree);
	return 0;
}
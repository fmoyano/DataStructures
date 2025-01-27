#include <stdio.h>
#include "binary_tree.h"

int main()
{
	Node* tree = bintree_create();
	Node* node10 = bintree_insert(tree, 10);
	Node* node5 = bintree_insert(tree, 5);
	Node* node2 = bintree_insert(tree, 2);
	Node* node7 = bintree_insert(tree, 7);
	Node* node20 = bintree_insert(tree, 20);
	Node* node30 = bintree_insert(tree, 30);
	Node* node15 = bintree_insert(tree, 15);
	Node* node14 = bintree_insert(tree, 14);

		// 10
	// 5       //20
// 2   //7   //15   //30
	       //14
	//printf("Value of the root = %d\n", tree->elem)
	bintree_print_left_first(tree);
	printf("\n\n");
	bintree_print_right_first(tree);

	printf("Min value: %d\n", bintree_value(bintree_min(tree)));
	printf("Max value: %d\n",  bintree_value(bintree_max(tree)));

	printf("Successor 10: %d\n",  bintree_value(bintree_successor(node10)));
	printf("Successor 5: %d\n",  bintree_value(bintree_successor(node5)));
	printf("Successor 2: %d\n",  bintree_value(bintree_successor(node2)));
	printf("Successor 7: %d\n",  bintree_value(bintree_successor(node7)));
	printf("Successor 14: %d\n",  bintree_value(bintree_successor(node14)));
	printf("Successor 15: %d\n",  bintree_value(bintree_successor(node15)));
	printf("Successor 20: %d\n",  bintree_value(bintree_successor(node20)));


	printf("Predecessor 10: %d\n",  bintree_value(bintree_predecessor(node10)));
	if (bintree_predecessor(node2)) printf("Predecessor 2: %d\n",  bintree_value(bintree_predecessor(node2)));
	printf("Predecessor 7: %d\n",  bintree_value(bintree_predecessor(node7)));
	printf("Predecessor 14: %d\n",  bintree_value(bintree_predecessor(node14)));
	printf("Predecessor 15: %d\n",  bintree_value(bintree_predecessor(node15)));
	printf("Predecessor 20: %d\n",  bintree_value(bintree_predecessor(node20)));
	printf("Predecessor 5: %d\n",  bintree_value(bintree_predecessor(node5)));

	if (bintree_successor(node30)) printf("Successor 30: %d\n",  bintree_value(bintree_successor(node30)));



	/*bool res = bintree_remove(tree, 0);
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

	printf("Min value: %d\n",  bintree_value(bintree_min(tree)));
	printf("Max value: %d\n",  bintree_value(bintree_max(tree)));*/

	return 0;
}
#include "common.h"

int main (int argc, int argv) {
	//struct binary_tree simple_tree;
	struct node *root = NULL;
	int array[10] = {5,7,2,4,1,3,9,8,6,10};
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		struct node *new = alloc_node(array[i]);
		if (node_add(&root, new) < 0) {
			printf("[ERROR]out of memory\n");
			return -1;
		}
	}
	printf("heigth of tree : %d\n", get_tree_high(root));
	pre_order_traversal(root);
	printf("\n");
	print_tree_graph(root, 8);
	free_all_node(root);
}

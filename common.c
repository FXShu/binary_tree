#include "common.h"

struct node *alloc_node(int value) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void free_all_node (struct node *root) {
	struct node *tmp;
	if (!root)
		return;
	tmp = root->left;
	free_all_node(tmp);
	tmp = root->right;
	free_all_node(tmp);
	free(root);

}

int node_add (struct node **root, struct node *node) {
	if (!node) 
		return -EINVAL;
	if (!(*root)) {
		*root = node;
		return 0;
	}

	if (node->value > (*root)->value) {
		node_add(&((*root)->right), node);
	} else {
		node_add(&((*root)->left), node);
	}
	return 0;
}

void pre_order_traversal(struct node *root) {
	if (!root)
		return;
	printf("%d ", root->value);
	pre_order_traversal(root->left);
	pre_order_traversal(root->right);
}

int get_tree_high(struct node *root) {
	if (!root)
		return 0;
	int lh = get_tree_high(root->left);
	int rh = get_tree_high(root->right);

	return 1 + MAX(lh, rh);
}

void print_tree_graph(struct node *root, int height) {
	if (!root)
		return;
	PRINT_SPACE(root->value, height);
	if (root->left) {
		PRINT_STRING_SPACE("/", height - 1);
		print_tree_graph(root->left, height - 2);
	}
	if (root->left) {
		PRINT_STRING_SPACE("\\", height + 1);
		print_tree_graph(root->right, height + 2);
	}
	return;

}

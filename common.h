#ifndef BINARY_TREE_COMMON_H
#define BINARY_TREE_COMMON_H
#include "include.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define PRINT_SPACE(str, space) printf("%"#space"d\n", (str));

#define PRINT_STRING_SPACE(str, space) printf("%"#space"s\n", (str));
struct node {
	struct node *left;
	struct node *right;
	int value;
};

struct binary_tree {
	struct node *root;
};

struct node *alloc_node(int value);

void free_all_node(struct node *node);

int node_add (struct node **root, struct node *node);

void pre_order_traversal(struct node *root);

int get_tree_high(struct node *root);

void print_tree_graph(struct node *root, int height);
#endif /* BINARY_TREE_COMMON_H */

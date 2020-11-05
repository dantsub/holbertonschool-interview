#include "binary_trees.h"
/**
 * sorted_array_to_avl - convert array to avl tree
 * @array: array to convert.
 * @size: size of array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	
	tree = recursive_tree(array, 0, (int)size - 1);
	if (!tree)
		return (NULL);
	return (tree);
}
/**
 * create_node - create node of avl_t
 * @n: number
 * Return: node or NULL
 */
avl_t *create_node(int n)
{
	avl_t *node = NULL;

	if (n == 0)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = n;
	return (node);
}
avl_t *recursive_tree(int *array, int ben, int end)
{
	avl_t *left = NULL, *right = NULL, *parent = NULL;
	size_t n = 0;

	if (ben > end)
		return (NULL);
	n = (ben + end) / 2;
	left = recursive_tree(array, ben, n - 1);
	right = recursive_tree(array, n + 1, end);
	parent = create_node(array[n]);
	parent->left = left;
	parent->right = right;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
	return (parent);
}

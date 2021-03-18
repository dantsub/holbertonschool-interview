#include "binary_trees.h"

/**
 * bt_height - goes through a binary tree using pre-order traversal
 * @tree: parent of node.
 * Return: nothing.
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);
	h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}
/**
 * is_balanced - goes through a binary tree using pre-order traversal
 * @tree: parent of node.
 * Return: nothing.
 */
int is_balanced(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	left = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right = tree->right ? (int)binary_tree_height(tree->right) : -1;
	return (left - right);
}
/**
* is_bst - check if a given tree is valid binary search tree or not
* @tree: parent of node.
* @min: lower limit of node value
* @max: upper limit of node value
* Return: 1 if bst, 0 otherwise
**/
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}
/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
* @tree: parent of node.
* Return: 1 if tree is a valid AVL Tree, and 0 if not or tree is NULL
**/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree != NULL && is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree))
		return (1);
	return (0);
}

#include "binary_trees.h"

/**
 * _abs - get the absolute value of a given number
 * @x: value to get the absolute value
 * Return: the absolute value of a given number
 */
int _abs(int x)
{
	return (x < 0 ? x * -1: x);
}
/**
* greater - finds the maximum number between two
* @left: fisrt number
* @right: second number
* Return: max of two numbers
**/
int greater(size_t left, size_t right)
{
	return (left >= right ? left : right);
}

/**
* find_height - finds the height of a binary tree.
* @tree: pointer to the root node.
* Return: height of tree
**/
int find_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + greater(find_height(tree->left), find_height(tree->right)));
}
/**
 * is_balanced - checks if a given bst is balanced.
 * @tree: pointer to the root node.
 * Return: nothing.
 */
int is_balanced(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (_abs(find_height(tree->left) - find_height(tree->right)) > 1)
		return (0);
	return (is_balanced(tree->left) && is_balanced(tree->right));
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
	if (!tree)
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
	if (!tree && is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree))
		return (1);
	return (0);
}

#include "binary_trees.h"

binary_tree_t *equal_anc(binary_tree_t *f, binary_tree_t *s);
binary_tree_t *not_eq_anc(binary_tree_t *f, binary_tree_t *s, int cf, int cs);
int count_ancestor(binary_tree_t *node);

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 *
 * Return: pointer to the lowest common ancestor or null
 *
 * @first: the first node
 *
 * @second: the second node
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	int anc_first, anc_second;
	binary_tree_t *f, *s;

	f = (binary_tree_t *)first;
	s = (binary_tree_t *)second;
	if (f == NULL || s == NULL)
		return (NULL);
	if (f == s)
		return (f);
	anc_first = count_ancestor(f);
	anc_second = count_ancestor(s);
	if (anc_first == anc_second)
	{
		return (equal_anc(f, s));
	}
	else
	{
		if (anc_first > anc_second)
			return (not_eq_anc(f, s, anc_first, anc_second));
		else if (anc_second > anc_first)
			return (not_eq_anc(s, f, anc_second, anc_first));
	}
	return (NULL);
}

/**
 * not_eq_anc - get common ancestor if parents not equal
 *
 * Return: the ancestor or NULL
 *
 * @f: the first point
 *
 * @s: the second point
 *
 * @cf: the count of ancestors of first point
 *
 * @cs: the count of ancestors of second point
*/

binary_tree_t *not_eq_anc(binary_tree_t *f, binary_tree_t *s, int cf, int cs)
{
	while (f->parent != NULL && cf > cs)
	{
		f = f->parent;
		if (f == s)
			return (f);
		cf--;
	}
	if (cf == cs)
		return (equal_anc(f, s));
	return (NULL);
}

/**
 * equal_anc - get common ancestor if parents equal
 *
 * Return: the ancestor or NULL
 *
 * @f: the first point
 *
 * @s: the second point
*/

binary_tree_t *equal_anc(binary_tree_t *f, binary_tree_t *s)
{
	while (f->parent || s->parent)
	{
		if (f->parent == s->parent)
			return (f->parent);
		f = f->parent;
		s = s->parent;
	}
	return (NULL);
}

/**
 * count_ancestor - count number of ancestors of a node in binary tree
 *
 * Return: the number of ancestors
 *
 * @node: the node to count its ancs
*/

int count_ancestor(binary_tree_t *node)
{
	int count = 0;

	while (node->parent != NULL)
	{
		count++;
		node = node->parent;
	}

	return (count);
}

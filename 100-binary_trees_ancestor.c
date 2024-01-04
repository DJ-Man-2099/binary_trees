#include "binary_trees.h"

binary_tree_t *equal_anc(binary_tree_t *f, binary_tree_t *s);
binary_tree_t *not_equal_anc(binary_tree_t *f, binary_tree_t *s, int cf, int cs);
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

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
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
			return (not_equal_anc(f, s, anc_first, anc_second));
		else if (anc_second > anc_first)
			return (not_equal_anc(s, f, anc_second, anc_first));
	}
	return (NULL);
}

binary_tree_t *not_equal_anc(binary_tree_t *f, binary_tree_t *s, int cf, int cs)
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

int count_ancestor(binary_tree_t *node)
{
	int count = 0;

	while (node->parent != NULL)
	{
		count++;
		node = node->parent;
	}

	return count;
}

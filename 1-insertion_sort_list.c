#include "sort.h"

/**
 * insertion_sort_list - C implementation of insertion sort algorithm
 * @list: list to sort
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n, *m;

	if (!list || !*list || !(*list)->next)
		return;

	n = (*list)->next;

	while (n)
	{
		m = n;
		n = n->next;
		while (m && m->prev)
		{
			if (m->prev->n > m->n)
			{
				node_swap(m->prev, m);
				if (m->prev == NULL)
					*list = m;
				print_list(*list);
			}
			else
				m = m->prev;
		}
	}
}


/**
 * node_swap - swap 2 nodes in doubly linked list
 * @x: first node
 * @y: second node
 *
 */

void node_swap(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

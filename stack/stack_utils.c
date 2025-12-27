/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:08:46 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:08:49 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. size of linked list
int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*node;

	node = stack;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

// 2. is linked list sorted
int	is_sorted(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return (1);
	node = stack;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

// 3. get min value on a linked list
int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*node;

	if (!stack)
		return (0);
	node = stack;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

// 4. get max index on a linked list
int	get_max_index(t_stack *a)
{
	t_stack	*node;
	int		max;

	node = a;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

// 5. get max bits based on max index
int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

/*
example:

max index = 568
1001010110

bits = 0;
(max_index >> bits)
1001010110 = 568

bits = 1;
(max_index >> bits)
0100101011 = 299

bits = 2;
(max_index >> bits)
0010010101 = 149

bits = 3;
(max_index >> bits)
0001001010 = 74

bits = 4;
(max_index >> bits)
0000100101 = 37

bits = 5
(max_index >> bits)
0000010010 = 18

bits = 6
(max_index >> bits)
0000001001 = 9

bits = 7
(max_index >> bits)
0000000100 = 4

bits = 8
(max_index >> bits)
0000000010 = 2

bits = 9
(max_index >> bits)
0000000001 = 1
*/

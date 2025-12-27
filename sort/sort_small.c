/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:13:01 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:05 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_nodes_sort(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	three_nodes_sort(t_stack **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f < s && s < t)
		return ;
	else if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

static void	move_min_to_top(t_stack **a)
{
	int		min;
	int		pos;
	int		size;
	t_stack	*tmp;

	min = get_min(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}

/*
a - 2 1 3 4 5
b - 

move_min_to_top
a - 2 3 4 5
b - 1

move_min_to_top
a - 3 4 5
b - 2 1 

three_nodes_sort
a - 3 4 5
b - 2 1 

pa 
a - 2 3 4 5
b - 1

pa 
a - 1 2 3 4 5
b -
*/

static void	more_nodes_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
		size--;
	}
	three_nodes_sort(a);
	while (*b)
		pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		two_nodes_sort(a);
	else if (size == 3)
		three_nodes_sort(a);
	else if (size > 3)
		more_nodes_sort(a, b);
}

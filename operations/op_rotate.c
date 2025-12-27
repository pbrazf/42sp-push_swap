/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:14:03 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:14:06 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate > first becomes last (A)
void	ra(t_stack **a)
{
	t_stack	*first;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	stack_add_back(a, first);
	write(1, "ra\n", 3);
}

// rotate > first becomes last (B)
void	rb(t_stack **b)
{
	t_stack	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	stack_add_back(b, first);
	write(1, "rb\n", 3);
}

// rotate > first becomes last (AB)
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

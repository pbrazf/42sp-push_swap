/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:13:38 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:41 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move the top element of B to the top of A
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

// move the top element of A to the top of B
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a || !a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

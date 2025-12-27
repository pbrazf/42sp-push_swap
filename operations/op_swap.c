/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:14:13 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:14:15 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp_value;
	int	tmp_index;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp_value = (*a)->value;
	tmp_index = (*a)->index;
	(*a)->value = (*a)->next->value;
	(*a)->index = (*a)->next->index;
	(*a)->next->value = tmp_value;
	(*a)->next->index = tmp_index;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp_value;
	int	tmp_index;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp_value = (*b)->value;
	tmp_index = (*b)->index;
	(*b)->value = (*b)->next->value;
	(*b)->index = (*b)->next->index;
	(*b)->next->value = tmp_value;
	(*b)->next->index = tmp_index;
	write(1, "sa\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

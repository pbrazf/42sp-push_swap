/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <pedrferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:48:02 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/27 21:48:19 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_stack **a, t_stack **b)
{
	int	size;
	int	max_index;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_index = get_max_index(*a);
	max_bits = get_max_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
/*
void	sort_radix(t_stack **a, t_stack **b)
{
	int	size;
	int	max_index;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a); // total number of nodes in A
	max_index = get_max_index(*a); // highest index present in stack A
	max_bits = get_max_bits(max_index); // number of bits required to represent 
	max_index (ex: 568 → 10 bits)
	i = 0;
	while (i < max_bits) // iterate through each bit position 
	(0 to max_bits - 1)
	{
		j = 0;
		while (j < size) // process every node that was originally in A
		{
			if (((*a)->index >> i) & 1) // if the i-th bit of the top index
			 is 1
				ra(a); // rotate A (move top to bottom)
			else
				pb(a, b); // push top of A to top of B
			j++;
		}
		while (*b) // after processing all nodes for this bit, empty B
			pa(a, b); // push everything back to A
		i++;
	}
}
*/
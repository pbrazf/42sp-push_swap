/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:10:04 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/25 21:10:06 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. start the linked list w the first node
t_stack	*stack_new(int value, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

// 2. add a new node in the back of the linked list
void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*ptr;

	if (!stack || !new_node)
		return ;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}

// 3. free all the stack
void	free_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	ptr = *stack;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*stack = NULL;
}

// 4. get and include new node w index
int	include_node(t_stack **head, int value, int *s_arr, int size)
{
	int		index;
	t_stack	*node;

	index = find_index(s_arr, size, value);
	if (index == -1)
		return (-1);
	node = stack_new(value, index);
	if (!node)
		return (-1);
	stack_add_back(head, node);
	return (1);
}

// 4. build the linked list 
t_stack	*build_stack_from_array(int *arr, int size)
{
	t_stack	*head;
	int		*sorted_arr;
	int		i;

	if (!arr || size <= 0)
		return (NULL);
	sorted_arr = sort_list(arr, size);
	if (!sorted_arr)
		return (NULL);
	head = NULL;
	i = 0;
	while (i < size)
	{
		if (include_node(&head, arr[i], sorted_arr, size) == -1)
		{
			free(sorted_arr);
			free_stack(&head);
			return (NULL);
		}
		i++;
	}
	free(sorted_arr);
	return (head);
}

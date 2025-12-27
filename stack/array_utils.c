/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <pedrferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:57:16 by pedrferr          #+#    #+#             */
/*   Updated: 2025/12/09 22:57:19 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*duplicate_list(int *arr, int size)
{
	int	*new_list;
	int	i;

	new_list = malloc(sizeof(int) * size);
	if (!new_list)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_list[i] = arr[i];
		i++;
	}
	return (new_list);
}

int	*sort_list(int *arr, int size)
{
	int	*sorted;
	int	i;
	int	j;
	int	tmp;

	sorted = duplicate_list(arr, size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[j] < sorted[i])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

int	find_index(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

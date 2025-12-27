/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:48:44 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/10 20:48:48 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Check that it is a num
static int	is_number(char *s)
{
	int	has_digit;

	has_digit = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		has_digit = 1;
		s++;
	}
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s != '\0' || !has_digit)
		return (0);
	return (1);
}

// 2. Convert the char *num to long long
static long long	ft_atol(char *s)
{
	long long	num;
	int			is_negative;

	is_negative = 0;
	num = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			is_negative = 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num *= 10;
		num += *s - '0';
		s++;
	}
	if (is_negative)
		num = -num;
	return (num);
}

// 3. Check that it is not duplicated
static int	is_duplicated(int *list, int list_size, long long num)
{
	int	i;

	i = 0;
	while (i < list_size)
	{
		if (list[i] == num)
			return (1);
		i++;
	}
	return (0);
}

// 4. Build a tmp list with the args (if all of them are valid)
int	*build_list(int count, char **args)
{
	int			*list;
	int			i;
	long long	num;

	list = malloc(sizeof(int) * count);
	if (!list)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!is_number(args[i]))
			return (free_and_null(list));
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free_and_null(list));
		if (is_duplicated(list, i, num))
			return (free_and_null(list));
		list[i] = (int)num;
		i++;
	}
	return (list);
}

// 5. Validate input args and return a tmp list with it
int	*validate_args(int argc, char **argv)
{
	char	**args;
	int		count;
	int		need_free;
	int		*list;

	if (argc == 2)
	{
		args = split_spaces(argv[1]);
		if (!args)
			return (NULL);
		need_free = 1;
		count = 0;
		while (args[count])
			count++;
	}
	else
	{
		args = argv + 1;
		count = argc - 1;
		need_free = 0;
	}
	list = build_list(count, args);
	if (need_free)
		free_split(args);
	return (list);
}

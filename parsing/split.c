/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:56:56 by pedrferr          #+#    #+#             */
/*   Updated: 2025/12/07 17:56:58 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ')
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*ft_strdup(char *str, int start, int end)
{
	char	*res;
	int		i;
	int		y;

	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	y = 0;
	i = start;
	while (i < end)
	{
		res[y] = str[i];
		y++;
		i++;
	}
	res[y] = '\0';
	return (res);
}

static int	free_list(char **list, int max_index)
{
	int	i;

	i = 0;
	while (i <= max_index)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (0);
}

static int	fill_list(char *str, char **list)
{
	int	start;
	int	i;
	int	x;

	i = 0;
	x = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		list[x] = ft_strdup(str, start, i);
		if (!list[x])
			return (free_list(list, x - 1));
		x++;
	}
	list[x] = NULL;
	return (1);
}

char	**split_spaces(char *str)
{
	char	**list;
	int		wc;

	wc = count_words(str);
	list = malloc(sizeof(char *) * (wc + 1));
	if (!list)
		return (NULL);
	if (!fill_list(str, list))
		return (NULL);
	return (list);
}

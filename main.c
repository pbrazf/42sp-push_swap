/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <pedrferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:44:21 by pedrferr          #+#    #+#             */
/*   Updated: 2025/12/09 22:44:24 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_push_swap(int *list, int count)
{
	t_stack	*a;
	t_stack	*b;

	a = build_stack_from_array(list, count);
	if (!a)
		return (free(list), error());
	b = NULL;
	if (is_sorted(a))
		return (free_stack(&a), free(list), 0);
	if (count <= 5)
		sort_small(&a, &b, count);
	else
		sort_radix(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free(list);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*list;
	int	count;

	if (argc == 1)
		return (0);
	if (argc == 2)
		count = count_words(argv[1]);
	else
		count = argc - 1;
	list = validate_args(argc, argv);
	if (!list)
		return (error());
	return (run_push_swap(list, count));
}

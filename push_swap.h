/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:35 by pedrferr          #+#    #+#             */
/*   Updated: 2025/11/10 20:48:23 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int value, int index);
t_stack	*build_stack_from_array(int *arr, int size);
int		error(void);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
char	**split_spaces(char *str);
int		count_words(char *str);
int		*validate_args(int argc, char **argv);
void	*free_and_null(void *p);
void	free_split(char **args);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_min(t_stack *stack);
int		*sort_list(int *arr, int size);
int		find_index(int *arr, int size, int num);
int		get_max_index(t_stack *a);
int		get_max_bits(int max_index);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_radix(t_stack **a, t_stack **b);

#endif

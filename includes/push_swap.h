/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:31:04 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/04 16:50:10 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Stack operations //
void				sa(t_stack **stack_a, t_list **result);
void				sb(t_stack **stack_b, t_list **result);
void				ss(t_stack **stack_a, t_stack **stack_b, t_list **result);
void				pa(t_stack **stack_a, t_stack **stack_b, t_list **result);
void				pb(t_stack **stack_a, t_stack **stack_b, t_list **result);
void				ra(t_stack **stack_a, t_list **result);
void				record_operation(t_list **result, const char *op);
void				rb(t_stack **stack_b, t_list **result);
void				rr(t_stack **stack_a, t_stack **stack_b, t_list **result);
void				rra(t_stack **stack_a, t_list **result);
void				rrb(t_stack **stack_b, t_list **result);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_list **result);
void				print_operations(t_list *operations);

// Parsing and validation //
int					validate_args(char **args, int *need_free);
int					is_valid_number(char *arg);
char				**parse_args(int argc, char **argv, int *need_free);

// Stack utilities //
t_stack				*init_stack(char **args, int need_free);
void				assign_index(t_stack *stack, int size);
long				parse_long(const char *str);
t_stack				*create_node(int num);
int					stack_len(t_stack *stack);
void				add_to_stack(t_stack **stack, t_stack *new);
void				ft_free_split(char **one_line);

/// General utilities //
void				clear_stack(t_stack **stack);
void				error_exit(t_stack **a, t_stack **b);
int					check_sorted(t_stack *stack);

// Sorting //
void				sort_stack(t_stack **a, t_stack **b, int size,
						t_list **result);
void				sort_three(t_stack **stack_a, t_list **result);
void				sort_five(t_stack **stack_a, t_stack **stack_b,
						t_list **result);
void				sort_chunks(t_stack **a, t_stack **b, int size,
						t_list **result);

#endif
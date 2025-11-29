/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:31:04 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/26 22:25:43 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Stack operations //
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// Parsing and validation //
int					validate_args(char **args);
int					is_valid_number(char *arg);

// Stack utilities //
t_stack				*init_stack(char **args);
void				assign_index(t_stack *stack, int size);
long				parse_long(const char *str);
t_stack				*create_node(int num);
int					stack_len(t_stack *stack);
void				add_to_stack(t_stack **stack, t_stack *new);

/// General utilities //
void				clear_stack(t_stack **stack);
void				error_exit(t_stack **a, t_stack **b);
int					check_sorted(t_stack *stack);

// Sorting //
void				sort_stack(t_stack **a, t_stack **b, int size);
void				sort_three(t_stack **stack_a);
void				sort_chunks(t_stack **a, t_stack **b, int size);

#endif

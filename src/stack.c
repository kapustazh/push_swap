/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/26 22:22:02 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*max_node;
	long		max_val;

	while (--size >= 0)
	{
		current = stack;
		max_node = NULL;
		max_val = LONG_MIN;
		while (current)
		{
			if (current->index == 0 && (long)current->value >= max_val)
			{
				max_val = current->value;
				max_node = current;
			}
			current = current->next;
		}
		if (max_node == NULL)
			break;
		max_node->index = size;
	}
}

static void	add_number(char *str, t_stack **stack)
{
	long	num;
	t_stack	*node;

	num = parse_long(str);
	if (num > INT_MAX || num < INT_MIN)
		error_exit(stack, NULL);
	node = create_node((int)num);
	if (!node)
		error_exit(stack, NULL);
	add_to_stack(stack, node);
}

t_stack	*init_stack(char **args)
{
	int		id;
	t_stack	*stack;

	id = 1;
	stack = NULL;
	while (args[id])
	{
		add_number(args[id], &stack);
		id++;
	}
	return (stack);
}

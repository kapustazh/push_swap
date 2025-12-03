/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/03 23:14:22 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_index(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*max_node;
	long	max_val;

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
			break ;
		max_node->index = size;
	}
}

static void	add_number(char *str, t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	long	nb;

	i = 0;
	while (str[i])
	{
		if (is_valid_number(&str[i]))
		{
			nb = parse_long(&str[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				error_exit(stack, NULL);
			tmp = create_node((int)nb);
			if (!tmp)
				error_exit(stack, NULL);
			add_to_stack(stack, tmp);
			while (is_valid_number(&str[i]))
				i++;
		}
		else
			i++;
	}
}

t_stack	*init_stack(char **args)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (args[i])
	{
		add_number(args[i], &stack);
		i++;
	}
	return (stack);
}

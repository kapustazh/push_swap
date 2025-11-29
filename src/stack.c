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
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
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

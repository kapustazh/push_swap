/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/26 22:22:02 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *arg)
{
	int	idx;

	idx = 0;
	if (arg[idx] == '-' || arg[idx] == '+')
		idx++;
	if (!arg[idx])
		return (0);
	while (arg[idx])
	{
		if (!ft_isdigit(arg[idx]))
			return (0);
		idx++;
	}
	return (1);
}

static int	check_duplicates(char **args)
{
	t_stack	*tmp;
	t_stack	*current;
	t_stack	*compare;

	tmp = init_stack(args);
	if (!tmp)
		return (1);
	current = tmp;
	while (current && current->next)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
			{
				clear_stack(&tmp);
				return (1);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	clear_stack(&tmp);
	return (0);
}

int	validate_args(char **args)
{
	int	idx;

	idx = 1;
	while (args[idx])
	{
		if (!is_valid_number(args[idx]))
			return (0);
		idx++;
	}
	if (check_duplicates(args))
		return (0);
	return (1);
}

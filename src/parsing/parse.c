/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/04 17:38:12 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_duplicates(char **args, int *need_free)
{
	t_stack	*tmp;
	t_stack	*current;
	t_stack	*compare;

	tmp = init_stack(args, *need_free);
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

int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}

char	**parse_args(int argc, char **argv, int *need_free)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_exit(NULL, NULL);
		*need_free = 1;
	}
	else
	{
		args = argv + 1;
		*need_free = 0;
	}
	if (!validate_args(args, need_free))
	{
		if (*need_free)
			ft_free_split(args);
		error_exit(NULL, NULL);
	}
	return (args);
}

int	validate_args(char **args, int *need_free)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			return (0);
		i++;
	}
	if (check_duplicates(args, need_free))
		return (0);
	return (1);
}

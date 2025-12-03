/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/03 23:38:37 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char	**parse_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_exit(NULL, NULL);
	}
	else
		args = argv + 1;
	if (!validate_args(args))
		error_exit(NULL, NULL);
	return (args);
}

static void	sort_and_print(char **args)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*result;
	int		len;

	a = init_stack(args);
	b = NULL;
	result = NULL;
	len = stack_len(a);
	assign_index(a, len);
	sort_stack(&a, &b, len, &result);
	print_operations(result);
	ft_lstclear(&result, free);
	clear_stack(&a);
	clear_stack(&b);
}

int	main(int argc, char **argv)
{
	char	**args;

	if (argc < 2)
		return (0);
	args = parse_args(argc, argv);
	sort_and_print(args);
	if (argc == 2)
		ft_free_split(args);
	return (0);
}

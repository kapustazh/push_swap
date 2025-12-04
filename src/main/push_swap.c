/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/04 17:43:04 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_and_print(char **args, int need_free)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*result;
	int		len;

	a = init_stack(args, need_free);
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
	int		need_free;

	if (argc < 2)
		return (0);
	args = parse_args(argc, argv, &need_free);
	sort_and_print(args, need_free);
	if (need_free)
		ft_free_split(args);
	return (0);
}

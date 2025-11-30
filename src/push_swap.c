/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 00:49:57 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*result;
	int		len;

	if (argc < 2)
		return (0);
	if (!validate_args(argv))
		error_exit(NULL, NULL);
	a = NULL;
	b = NULL;
	result = NULL;
	a = init_stack(argv);
	len = stack_len(a);
	assign_index(a, len);
	sort_stack(&a, &b, len, &result);
	print_operations(result);
	ft_lstclear(&result, free);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

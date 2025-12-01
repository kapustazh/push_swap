/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:19:21 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 22:16:29 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!validate_args(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = init_stack(argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	b = NULL;
	read_operations(&a, &b);
	return (0);
}

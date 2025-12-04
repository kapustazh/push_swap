/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:19:21 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/04 17:40:46 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		need_free;

	if (argc < 2)
		return (0);
	args = parse_args(argc, argv, &need_free);
	a = init_stack(args, need_free);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		if (need_free)
			ft_free_split(args);
		return (1);
	}
	b = NULL;
	read_operations(&a, &b);
	if (need_free)
		ft_free_split(args);
	return (0);
}

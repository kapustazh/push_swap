/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/26 22:23:49 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (*from == NULL)
		return ;
	node = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	do_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	do_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

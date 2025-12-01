/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 20:08:30 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_rev_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	tail = before_last->next;
	before_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_stack **stack_a, t_list **result)
{
	record_operation(result, "rra");
	do_rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b, t_list **result)
{
	record_operation(result, "rrb");
	do_rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_list **result)
{
	record_operation(result, "rrr");
	do_rev_rotate(stack_a);
	do_rev_rotate(stack_b);
}

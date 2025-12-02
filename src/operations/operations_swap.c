/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/02 18:24:28 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	second = (*stack)->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

void	sa(t_stack **stack_a, t_stack **result)
{
	record_operation(result, "sa");
	do_swap(stack_a);
}

void	sb(t_stack **stack_b, t_stack **result)
{
	record_operation(result, "sb");
	do_swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_stack **result)
{
	record_operation(result, "ss");
	do_swap(stack_a);
	do_swap(stack_b);
}

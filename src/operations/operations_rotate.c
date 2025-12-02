/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/02 18:24:25 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_stack **stack_a, t_stack **result)
{
	record_operation(result, "ra");
	do_rotate(stack_a);
}

void	rb(t_stack **stack_b, t_stack **result)
{
	record_operation(result, "rb");
	do_rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_stack **result)
{
	record_operation(result, "rr");
	do_rotate(stack_a);
	do_rotate(stack_b);
}

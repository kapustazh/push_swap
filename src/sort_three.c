/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:55:54 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/13 00:33:32 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Finds the node with the highest index in the stack.
 *
 * @param stack_a Pointer to the stack.
 * @return        Pointer to the node with the highest index, or NULL if empty.
 */
static t_stack	*get_highest(t_stack **stack_a)
{
	int		highest;
	t_stack	*highest_node;
	t_stack	*cur;

	if (!stack_a || !*stack_a)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	cur = *stack_a;
	while (cur)
	{
		if (cur->index > highest)
		{
			highest = cur->index;
			highest_node = cur;
		}
		cur = cur->next;
	}
	return (highest_node);
}

void	sort_three(t_stack **stack_a)
{
	t_stack *highest;

	highest = get_highest(stack_a);
	if ((*stack_a)->index == highest->index)
		ra(stack_a);
	else if ((*stack_a)->next->index == highest->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
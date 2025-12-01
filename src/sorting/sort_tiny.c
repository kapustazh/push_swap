/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:55:54 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 20:09:02 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sort_three(t_stack **stack_a, t_list **result)
{
	t_stack	*highest;

	highest = get_highest(stack_a);
	if ((*stack_a)->index == highest->index)
		ra(stack_a, result);
	else if ((*stack_a)->next->index == highest->index)
		rra(stack_a, result);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, result);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_list **result)
{
	while (stack_len(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b, result);
		else
			ra(stack_a, result);
	}
	sort_three(stack_a, result);
	pa(stack_a, stack_b, result);
	pa(stack_a, stack_b, result);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, result);
}

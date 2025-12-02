/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:33:24 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/02 18:47:06 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	calc_sqrt(int num)
{
	long	sqrt_candidate;

	sqrt_candidate = 0;
	if (num < 1)
		return (0);
	while (sqrt_candidate * sqrt_candidate < (long)num)
		sqrt_candidate++;
	if (sqrt_candidate * sqrt_candidate == (long)num)
		return (sqrt_candidate);
	return ((int)sqrt_candidate - 1);
}

/*
 * divide_chunks:
 *  Divides stack A into chunks and pushes all elements to stack B.
 *  Uses a chunk width based on the square root of the size.
 */
static void	divide_chunks(t_stack **a, t_stack **b, int size, t_list **result)
{
	int	current_min_index;
	int	chunk_width;

	current_min_index = 0;
	chunk_width = calc_sqrt(size) * 14 / 10;
	while (*a)
	{
		if ((*a)->index <= current_min_index)
		{
			pb(a, b, result);
			if (*a && ((*a)->index <= current_min_index
					|| (*a)->index <= current_min_index + chunk_width))
				rb(b, result);
			else
				rr(a, b, result);
			current_min_index++;
		}
		else if ((*a)->index <= current_min_index + chunk_width)
		{
			pb(a, b, result);
			current_min_index++;
		}
		else
			ra(a, result);
	}
}

/*
 * count_rotations:
 *  Counts how many forward rotations are needed in stack B
 *  to bring the element with index size - 1 to the top.
 */
static int	count_rotations(t_stack *stack, int size)
{
	int	forward_rotations;

	forward_rotations = 0;
	while (stack && stack->index != (size - 1))
	{
		forward_rotations++;
		stack = stack->next;
	}
	return (forward_rotations);
}

/*
 * sort_chunks:
 *  Sorts the stack using a chunk-based approach.
 *  1. Divides stack A into chunks and pushes all elements to stack B.
 *  2. Pulls elements back from B to A in sorted order,
 *     choosing the optimal rotation direction each time.
 */
void	sort_chunks(t_stack **a, t_stack **b, int size, t_list **result)
{
	int	forward_rotations;
	int	reverse_rotations;

	divide_chunks(a, b, size, result);
	while (size - 1 >= 0)
	{
		forward_rotations = count_rotations(*b, size);
		reverse_rotations = size - forward_rotations;
		if (forward_rotations <= reverse_rotations)
		{
			while ((*b)->index != size - 1)
				rb(b, result);
			pa(a, b, result);
			size--;
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b, result);
			pa(a, b, result);
			size--;
		}
	}
}

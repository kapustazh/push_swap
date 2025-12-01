/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:33:24 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 22:39:34 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * calc_sqrt:
 *  Returns the integer square root of `num`,
 *  i.e. the largest integer `x` such that x*x <= num.
 *  Used to decide a chunk size based on the input size.
 */
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
 *  Splits stack A into chunks and pushes all elements to stack B.
 *  - `current_min_index` tracks the next smallest index that should move.
 *  - `chunk_width` defines how wide each chunk (index range) is.
 *  Elements with index:
 *    - <= current_min_index: pushed to B and B is rotated to sink them.
 *    - within (current_min_index, current_min_index + chunk_width]:
 *        pushed to B without rotation.
 *    - greater: A is rotated to search for better candidates.
 *  This arrangement makes it easier later to pull back elements from B in order.
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
 *  Counts how many forward rotations (rb) are needed
 *  to bring the element with index (size - 1) to the top of `stack`.
 *  This is used to choose between rotating forward or reverse.
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
 *  High-level algorithm:
 *    1) Use divide_chunks to push all elements from A to B in chunks.
 *    2) Then, while there are elements left:
 *         - Find how far the current max index (size - 1) is from top of B.
 *        
	- Decide if it’s cheaper to rotate B forwards (rb) or backwards (rrb).
 *         - Rotate B until that max is on top.
 *         - Push it back to A (pa).
 *         - Decrease size (one more element is correctly placed in A).
 *  After the loop, stack A is sorted in ascending order by index/value.
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

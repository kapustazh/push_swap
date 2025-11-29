/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/29 15:50:42 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calc_sqrt(int num)
{
	long	val;

	val = 0;
	if (num < 1)
		return (0);
	while (val * val < (long)num)
		val++;
	if (val * val == (long)num)
		return (val);
	return ((int)val - 1);
}

static void	divide_chunks(t_stack **a, t_stack **b, int size)
{
	int	counter;
	int	chunk_size;

	counter = 0;
	chunk_size = calc_sqrt(size) * 14 / 10;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			if (*a && ((*a)->index <= counter || (*a)->index <= counter
					+ chunk_size))
				rb(b);
			else
				rr(a, b);
			counter++;
		}
		else if ((*a)->index <= counter + chunk_size)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

static int	count_rotations(t_stack *stack, int size)
{
	int	rotations;

	rotations = 0;
	while (stack && stack->index != (size - 1))
	{
		rotations++;
		stack = stack->next;
	}
	return (rotations);
}

void	sort_chunks(t_stack **a, t_stack **b, int size)
{
	int	rot;
	int	rev_rot;

	divide_chunks(a, b, size);
	while (size - 1 >= 0)
	{
		rot = count_rotations(*b, size);
		rev_rot = size - rot;
		if (rot <= rev_rot)
		{
			while ((*b)->index != size - 1)
				rb(b);
			pa(a, b);
			size--;
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b);
			pa(a, b);
			size--;
		}
	}
}


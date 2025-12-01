/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:21:14 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 22:31:41 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "push_swap.h"

static void	error_and_exit(t_stack **a, t_stack **b)
{
	ft_putstr_fd("Error\n", 2);
	clear_stack(a);
	clear_stack(b);
	exit(1);
}

static int	apply_two_op(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		sa(a, NULL);
	else if (ft_strncmp(line, "sb", 3) == 0)
		sb(b, NULL);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ss(a, b, NULL);
	else if (ft_strncmp(line, "pa", 3) == 0)
		pa(a, b, NULL);
	else if (ft_strncmp(line, "pb", 3) == 0)
		pb(a, b, NULL);
	else if (ft_strncmp(line, "ra", 3) == 0)
		ra(a, NULL);
	else if (ft_strncmp(line, "rb", 3) == 0)
		rb(b, NULL);
	else if (ft_strncmp(line, "rr", 3) == 0)
		rr(a, b, NULL);
	else
		return (0);
	return (1);
}

static int	apply_three_op(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "rra", 4) == 0)
		rra(a, NULL);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rrb(b, NULL);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		rrr(a, b, NULL);
	else
		return (0);
	return (1);
}

static void	apply_op(char *line, t_stack **a, t_stack **b)
{
	size_t	len;

	if (!line)
		error_and_exit(a, b);
	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (apply_two_op(line, a, b))
		return ;
	if (apply_three_op(line, a, b))
		return ;
	error_and_exit(a, b);
}

void	read_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line[0] == '\0')
		{
			free(line);
			error_and_exit(a, b);
		}
		apply_op(line, a, b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (check_sorted(*a) && *b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(a);
	clear_stack(b);
}

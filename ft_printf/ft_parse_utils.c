/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:42:59 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/09 20:26:33 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

static int	ft_isspec(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#' || c == '.'
		|| c == '*')
		return (1);
	return (0);
}

int	ft_isflag(char c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspec(c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:51:07 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 13:03:26 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_checker(long num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count = 1;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*fill_digits(char *digit, long num)
{
	int	len;
	int	i;

	len = size_checker(num);
	i = len - 1;
	digit[len] = '\0';
	if (num == 0)
	{
		digit[0] = '0';
		return (digit);
	}
	if (num < 0)
	{
		digit[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		digit[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;

	num = n;
	str = (char *)malloc(size_checker(num) + 1);
	if (!str)
		return (NULL);
	return (fill_digits(str, num));
}

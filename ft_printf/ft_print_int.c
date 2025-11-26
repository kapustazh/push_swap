/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:17:42 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/10 09:12:05 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_precision(char *nb_str, int precision)
{
	int		len;
	int		zeros;
	char	*res;
	int		i;
	int		neg;

	len = ft_strlen(nb_str);
	neg = (nb_str[0] == '-');
	zeros = precision - (len - neg);
	if (zeros <= 0)
		return (nb_str);
	res = malloc(sizeof(char) * (precision + neg + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (neg)
		res[i++] = '-';
	while (zeros-- > 0)
		res[i++] = '0';
	while (nb_str[neg])
		res[i++] = nb_str[neg++];
	res[i] = '\0';
	free(nb_str);
	return (res);
}

static char	*ft_apply_sign(int n, char *nb_str, t_flags flags)
{
	char	*res;

	res = NULL;
	if (n >= 0 && flags.plus == 1)
		res = ft_strjoin("+", nb_str);
	else if (n >= 0 && flags.space == 1)
		res = ft_strjoin(" ", nb_str);
	else
		res = ft_strdup(nb_str);
	free(nb_str);
	return (res);
}

int	ft_print_with_zero(char *nb_str, t_flags flags)
{
	int	count;

	count = 0;
	if (nb_str[0] == '-' || nb_str[0] == '+' || nb_str[0] == ' ')
	{
		count += ft_print_c(nb_str[0]);
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 1);
		count += ft_print_numstr(nb_str + 1);
	}
	else
	{
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 1);
		count += ft_print_numstr(nb_str);
	}
	return (count);
}

int	ft_print_int(int n, t_flags flags)
{
	int		count;
	char	*nb_str;

	if (flags.precision == 0 && n == 0)
		return (ft_pad_width(flags.width, 0, 0));
	count = 0;
	nb_str = ft_itoa(n);
	if (!nb_str)
		return (0);
	nb_str = ft_apply_precision(nb_str, flags.precision);
	if (!nb_str)
		return (0);
	nb_str = ft_apply_sign(n, nb_str, flags);
	if (flags.left == 1)
		count += ft_print_numstr(nb_str) + ft_pad_width(flags.width,
				ft_strlen(nb_str), 0);
	else if (flags.zero && flags.precision < 0)
		count += ft_print_with_zero(nb_str, flags);
	else
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 0)
			+ ft_print_numstr(nb_str);
	free(nb_str);
	return (count);
}

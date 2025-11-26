/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:40:19 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/13 18:47:49 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa_printf(unsigned int n)
{
	char	buf[20];
	char	*res;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = -1;
	while (n > 0)
	{
		buf[++i] = (n % 10) + '0';
		n /= 10;
	}
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	while (i >= 0)
		res[n++] = buf[i--];
	res[n] = '\0';
	return (res);
}

int	ft_print_uint(unsigned int n, t_flags flags)
{
	int		count;
	char	*nb_str;

	if (flags.precision == 0 && n == 0)
		return (ft_pad_width(flags.width, 0, 0));
	count = 0;
	nb_str = ft_utoa_printf(n);
	if (!nb_str)
		return (0);
	nb_str = ft_apply_precision(nb_str, flags.precision);
	if (!nb_str)
		return (0);
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

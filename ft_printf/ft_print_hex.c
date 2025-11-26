/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:22:03 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/10 10:51:01 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hex(unsigned long nb, char *base)
{
	char	buf[20];
	char	*res;
	int		i;
	int		j;

	if (nb == 0)
		return (ft_strdup("0"));
	i = -1;
	while (nb > 0)
	{
		buf[++i] = (base[nb % 16]);
		nb /= 16;
	}
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	j = 0;
	while (i >= 0)
		res[j++] = buf[i--];
	res[j] = '\0';
	return (res);
}

static char	*ft_apply_hash(char *hex_str, unsigned int n, int is_upper,
		t_flags flags)
{
	char	*res;

	if (flags.hash && n != 0)
	{
		if (is_upper)
			res = ft_strjoin("0X", hex_str);
		else
			res = ft_strjoin("0x", hex_str);
		free(hex_str);
		return (res);
	}
	return (hex_str);
}

static int	ft_print_hex_zero(char *nb_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash && nb_str[1] == 'x')
	{
		count += ft_print_numstr("0x");
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 1);
		count += ft_print_numstr(nb_str + 2);
	}
	else if (flags.hash && nb_str[1] == 'X')
	{
		count += ft_print_numstr("0X");
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 1);
		count += ft_print_numstr(nb_str + 2);
	}
	else
	{
		count += ft_pad_width(flags.width, ft_strlen(nb_str), 1);
		count += ft_print_numstr(nb_str);
	}
	return (count);
}

static int	ft_print_hexstr(char *hex_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_numstr(hex_str) + ft_pad_width(flags.width,
				ft_strlen(hex_str), 0);
	else if (flags.zero && flags.precision < 0)
		count += ft_print_hex_zero(hex_str, flags);
	else
		count += ft_pad_width(flags.width, ft_strlen(hex_str), 0)
			+ ft_print_numstr(hex_str);
	free(hex_str);
	return (count);
}

int	ft_print_hex(unsigned int n, int is_upper, t_flags flags)
{
	int		count;
	char	*hex_str;
	char	*base;

	count = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0 && flags.precision == 0)
		return (ft_pad_width(flags.width, 0, 0));
	hex_str = ft_itoa_hex((unsigned long)n, base);
	if (!hex_str)
		return (0);
	hex_str = ft_apply_precision(hex_str, flags.precision);
	if (!hex_str)
		return (0);
	hex_str = ft_apply_hash(hex_str, n, is_upper, flags);
	count += ft_print_hexstr(hex_str, flags);
	return (count);
}

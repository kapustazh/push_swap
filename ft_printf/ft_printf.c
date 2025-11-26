/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:28:57 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/09 21:21:38 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(char type, va_list *args, t_flags flags)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_char('%', flags);
	if (type == 'c')
		count += ft_print_char(va_arg(*args, int), flags);
	if (type == 's')
		count += ft_print_str(va_arg(*args, const char *), flags);
	if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(*args, int), flags);
	if (type == 'x')
		count += ft_print_hex(va_arg(*args, unsigned int), 0, flags);
	if (type == 'X')
		count += ft_print_hex(va_arg(*args, unsigned int), 1, flags);
	if (type == 'u')
		count += ft_print_uint(va_arg(*args, unsigned int), flags);
	if (type == 'p')
		count += ft_print_ptr(va_arg(*args, void *), flags);
	return (count);
}

static int	ft_return_spec(const char *str, int i, t_flags *flags)
{
	if (str[i] == '%')
		flags->width = 0;
	flags->spec = str[i];
	return (i);
}

static int	ft_parse_flags(const char *str, int i, va_list *args,
		t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flags_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flags_prec(str, i, args, flags);
		if (str[i] == '*')
			*flags = ft_flags_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flags_digit(str[i], *flags);
		if (ft_istype(str[i]))
			return (ft_return_spec(str, i, flags));
	}
	return (i);
}

static int	ft_parse(char *str, va_list *args)
{
	int		i;
	int		count;
	t_flags	flags;

	count = 0;
	i = -1;
	while (str[++i])
	{
		flags = ft_flags_init();
		if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse_flags(str, i, args, &flags);
			if (str[i] && flags.spec && ft_istype(str[i]))
				count += ft_print_arg(str[i], args, flags);
			else if (str[i])
				count += ft_print_char(str[i], flags);
		}
		else
			count += ft_print_c(str[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_parse((char *)format, &args);
	va_end(args);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:26:43 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/14 10:26:45 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptrstr(char *ptr_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_numstr(ptr_str) + ft_pad_width(flags.width,
				ft_strlen(ptr_str), 0);
	else
		count += ft_pad_width(flags.width, ft_strlen(ptr_str), 0)
			+ ft_print_numstr(ptr_str);
	return (count);
}

int	ft_print_ptr(void *ptr, t_flags flags)
{
	unsigned long	addr;
	int				count;
	char			*ptr_str;
	char			*tmp;

	addr = (unsigned long)ptr;
	if (addr == 0 && flags.precision == 0)
		ptr_str = ft_strdup("0x");
	else if (addr == 0)
		ptr_str = ft_strdup("(nil)");
	else
	{
		ptr_str = ft_itoa_hex(addr, "0123456789abcdef");
		if (!ptr_str)
			return (0);
		ptr_str = ft_apply_precision(ptr_str, flags.precision);
		if (!ptr_str)
			return (0);
		tmp = ft_strjoin("0x", ptr_str);
		free(ptr_str);
		ptr_str = tmp;
	}
	count = ft_print_ptrstr(ptr_str, flags);
	free(ptr_str);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:43:21 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/10 10:50:49 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_istype(char c);
int		ft_isflag(char c);
t_flags	ft_flags_init(void);
t_flags	ft_flags_left(t_flags flags);
int		ft_flags_prec(const char *str, int pos, va_list *args, t_flags *flags);
t_flags	ft_flags_width(va_list *args, t_flags flags);
t_flags	ft_flags_digit(char c, t_flags flags);
int		ft_print_c(char c);
int		ft_print_char(char c, t_flags flags);
int		ft_pad_width(int width, int size, int zero);
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_numstr(const char *str);
int		ft_print_int(int n, t_flags flags);
char	*ft_apply_precision(char *nb_str, int precision);
int		ft_print_with_zero(char *nb_str, t_flags flags);
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
char	*ft_itoa_hex(unsigned long nb, char *base);
int		ft_print_uint(unsigned int n, t_flags flags);
int		ft_print_ptr(void *ptr, t_flags flags);

#endif // !FT_PRINTF_H

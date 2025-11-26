/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:17:01 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/08 18:17:04 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	buf[12];
	char	*res;
	long	nb;
	int		i;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb = -nb;
	i = -1;
	while (nb > 0)
	{
		buf[++i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		buf[++i] = '-';
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	while (i >= 0)
		res[nb++] = buf[i--];
	res[nb] = '\0';
	return (res);
}

// reusing nb in the end because we are sure that nb = 0 after first loop

// #include <limits.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*str;
// 	int		n;
//
// 	n = INT_MIN;
// 	if (!(str = ft_itoa(n)))
// 		printf("Error");
// 	else
// 		printf("%s\n", str);
// 	free(str);
// }

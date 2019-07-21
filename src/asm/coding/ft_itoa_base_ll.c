/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:19:47 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/15 19:03:05 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int		ft_num_dig(uintmax_t n, int base)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= 16;
	}
	return (res);
}

static void		turn_into_char(char *res, uintmax_t n,
								int base, int num_d)
{
	char	*buf;

	buf = "0123456789abcdef";
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[n % base];
		n /= base;
	}
}

char			*ft_itoa_base(uintmax_t n, int base)
{
	char	*res;
	int		num_d;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		res[0] = '0';
		res[1] = '0';
		res[2] = '\0';
	}
	else
	{
		num_d = ft_num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char(res, n, base, num_d);
	}
	return (res);
}

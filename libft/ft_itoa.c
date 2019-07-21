/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:17:00 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:53:45 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_get_number(char *c, long int n, int cap)
{
	int a;

	a = 1;
	while (--cap)
	{
		a *= 10;
	}
	while (a > 1)
	{
		*c++ = n / a + '0';
		n = n % a;
		a /= 10;
	}
	*c++ = n + '0';
	*c = '\0';
}

char			*ft_itoa(int n)
{
	char			*res;
	char			*temp;
	int				cap;
	long int		num;

	cap = ft_capacity(n);
	res = (char*)malloc(sizeof(char) * (cap + 1));
	temp = res;
	num = (long int)n;
	if (res)
	{
		if (num < 0)
		{
			cap--;
			*temp++ = '-';
			num *= -1;
		}
		ft_get_number(temp, num, cap);
	}
	return (res);
}

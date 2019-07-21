/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capacity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:27:50 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:52:46 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_capacity(int n)
{
	int			res;
	long int	num;

	num = (long int)n;
	res = 1;
	if (n < 0)
	{
		num *= -1;
		res++;
	}
	while (num >= 10)
	{
		res++;
		num /= 10;
	}
	return (res);
}

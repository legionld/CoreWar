/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:19:39 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 01:17:36 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					z;

	z = 1;
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		z = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& str[i] > '7')) && z == 1)
			return (-1);
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& str[i] > '8')) && z == -1)
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)res * z);
}

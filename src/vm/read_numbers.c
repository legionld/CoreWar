/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:21:07 by smight            #+#    #+#             */
/*   Updated: 2019/07/14 18:21:09 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

short			read_short(int start_i, t_battle *b)
{
	short	sum;
	int		i;

	sum = 0;
	i = -1;
	while (++i < 2)
	{
		sum = sum * 256 + b->ring[start_i].code;
		start_i = g_index(start_i + 1);
	}
	return (sum);
}

unsigned int	read_int(int start_i, t_battle *b)
{
	unsigned int	sum;
	int				i;

	sum = 0;
	i = -1;
	while (++i < 4)
	{
		sum = sum * 256 + b->ring[start_i].code;
		start_i = g_index(start_i + 1);
	}
	return (sum);
}

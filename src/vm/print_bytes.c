/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:15:56 by smight            #+#    #+#             */
/*   Updated: 2019/07/08 21:15:57 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	print_champion(int fd)
{
	unsigned char	buff;
	int 			cnt1;
	int 			cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (read(fd, &buff, 1))
	{
		printf("%02hx", (unsigned short)buff);
		cnt1++;
		cnt2++;
		if (cnt2 == 16)
		{
			printf("\n");
			cnt1 = 0;
			cnt2 = 0;
		}
		else if (cnt1 == 2)
		{
			printf(" ");
			cnt1 = 0;
		}
	}
}

int 	check_carr(t_battle *b, int index)
{
	t_carr	*carr;

	carr = b->carrs;
	while (carr)
	{
		if (carr->current_i == index)
			return (1);
		carr = carr->next;
	}
	return (0);
}

void	print_map(t_battle *b)
{
	int	i;
	int row_number;

	i = -1;
	row_number = 64;
	printf("0x0000 : ");
	while (++i < MEM_SIZE)
	{
		if (check_carr(b, i))
			printf("\x1B[31m");
		printf("%02hx", (unsigned short)b->ring[i].code);
		if (check_carr(b, i))
			printf("\x1B[00m");
		if ((i + 1) % 64 == 0)
		{
			if (i != MEM_SIZE - 1)
				printf(" \n%0#6x : ", row_number);
			row_number += 64;
		}
		else
			printf(" ");
	}
	printf(" \n");
}

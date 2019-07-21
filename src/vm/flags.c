/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:53:13 by smight            #+#    #+#             */
/*   Updated: 2019/07/17 14:53:15 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

char 	*op_name(unsigned char code)
{
	if (code == 1 || code == 2)
		return (code == 1 ? "live" : "ld");
	else if (code == 3 || code == 4)
		return (code == 3 ? "st" : "add");
	else if (code == 5 || code == 6)
		return (code == 5 ? "sub" : "and");
	else if (code == 7 || code == 8)
		return (code == 7 ? "or" : "xor");
	else if (code == 9 || code == 10)
		return (code == 9 ? "zjmp" : "ldi");
	else if (code == 11 || code == 12)
		return (code == 11 ? "sti" : "fork");
	else if (code == 13 || code == 14)
		return (code == 13 ? "lld" : "lldi");
	else if (code == 15 || code == 16)
		return (code == 15 ? "lfork" : "aff");
	return (NULL);
}

int 	p_16_len(t_battle *b, int c_index, unsigned char command)
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	int 			len;
	int 			dir_len;

	p1 = 0;
	p2 = 0;
	p3 = 0;
	if ((b->ring[c_index].code >= 9 && b->ring[c_index].code <= 12)\
	|| b->ring[c_index].code == 14 || b->ring[c_index].code == 15)
		dir_len = 2;
	else
		dir_len = 4;
	if (b->ring[c_index].code == 1 || b->ring[c_index].code == 9 ||\
	b->ring[c_index].code == 12 || b->ring[c_index].code == 15)
		return (1 + dir_len);
	read_args(&p1, &p2, &p3, b->ring[c_index + 1].code);
	if ((command >= 1 && command <= 3) || command == 9 || command == 12 || command == 13 || command == 15 || command == 16)
		p3 = 0;
	if (command == 1 || command == 9 || command == 12 || command == 15 || command == 16)
		p2 = 0;
	len = 2 + (p1 != 0 ? shift_len(p1, dir_len) : 0) +\
	(p2 != 0 ? shift_len(p2, dir_len) : 0) +\
	(p3 != 0 ? shift_len(p3, dir_len) : 0);
	return (len);
}

void 	print_16_p(t_battle	*b, int c_index)
{
	int		i;
	int		len;

	i = c_index;
	//if (b->ring[c_index].code == 9)
	//	return ;
	len = p_16_len(b, c_index, b->ring[c_index].code);
	if (i == 0)
		printf("ADV %d (0x0000 -> %0#6x) ", len, i + len);
	else if (i + len == 0)
		printf("ADV %d (%0#6x -> 0x0000) ", len, i);
	else
		printf("ADV %d (%0#6x -> %0#6x) ", len, i, i + len);
	c_index += len;
	while (i < c_index)
	{
		printf("%02hx ", (unsigned short)b->ring[g_index(i)].code);
		i++;
	}
	printf("\n");
}

int	 	read_flags(t_battle *b, int *i, char **v, int c)
{
	if (!ft_strncmp(v[*i], "-dump", 5) && *i + 1 < c)//если нашелся думп - беру атои из след. аргумента
	{
		b->dump_number = ft_atoi(v[++(*i)]);
		return (1);
	}
	else if (!ft_strncmp(v[*i], "-v", 5) && *i + 1 < c)
	{
		b->v_params = ft_atoi(v[++(*i)]);
		return (1);
	}
	return (0);
}

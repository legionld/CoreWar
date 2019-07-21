/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:48:13 by smight            #+#    #+#             */
/*   Updated: 2019/07/21 23:25:16 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void			write_int(t_battle *b, unsigned int nb, int start_i)
{
	int	i;

	i = -1;
	start_i = g_index(start_i);
	while (++i < 4)
	{
		b->ring[g_index(start_i)].code = (unsigned char)nb;
		nb = nb >> 8u;
		start_i = g_index(start_i - 1);
	}
}

void			write_carr_position(t_battle *b, int part)
{
	t_carr	*tmp;
	int 	add;

	tmp = b->carrs;
	while (tmp && tmp->next)
		tmp = tmp->next;
	add = 0;
	while (tmp)
	{
		tmp->current_i = g_index(add);
		add += part;
		tmp = tmp->prev;
	}
}

void			write_player_operations(t_battle *b, int ring_index, int p_index)
{
	int	i;

	i = -1;
	while (++i < b->champs[p_index]->code_size)
	{
		b->ring[ring_index++].code = b->champs[p_index]->code[i];
		b->ring[ring_index++].user = p_index;
	}
}

void			write_operations_to_ring(t_battle *b)
{
	int i;
	int part;
	int start;

	i = -1;
	part = 0;
	while (++i < MAX_PLAYERS)
		b->champs[i] ? part++ : 0;
	i = -1;
	start = 0;
	part = MEM_SIZE / part;
	write_carr_position(b, part);
	while (++i < MAX_PLAYERS)
	{
		if (b->champs[i])
		{
			write_player_operations(b, start, i);
			start += part;
		}
	}
}

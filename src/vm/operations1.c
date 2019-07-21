/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:27:24 by smight            #+#    #+#             */
/*   Updated: 2019/07/12 16:27:25 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	live(t_battle *b, t_carr *carr)//-v 4
{
	carr->current_i = g_index(carr->current_i + 1);
	b->v_params == 4 ? printf("P%5d | %s %u", carr->global_i,\
	op_name(carr->code_op), read_int(carr->current_i, b)) : 0;
	carr->cycle_live = b->cycle_count;//carr is live
	b->last_live = b->cycle_count;
	if (read_int(carr->current_i, b) == carr->regs[0])
	{
		if (b->v_params == 1)
			printf("Player %d (%s) is said to be alive\n", carr->number, w_name(b, carr->number));
	}
	b->last_live_cnt++;
	carr->current_i = g_index(carr->current_i + 4);
	b->last_live_player = carr->number;
	b->v_params == 4 ? printf("\n") : 0;
}

void		ld(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	int				nb1;

	carr->current_i = g_index(carr->current_i + 1);
	b->v_params == 4 ? printf("P%5d | ld ", carr->global_i) : 0;
	read_args(&p1, &p2, NULL, b->ring[carr->current_i].code);
	if (p2 == REG && (p1 == DIR || p1 == IND) &&\
	!(p1 == DIR && !is_valid_reg(b->ring[g_index(carr->current_i + 5)].code)) &&\
	!(p1 == IND && !is_valid_reg(b->ring[g_index(carr->current_i + 3)].code)))
	{
		carr->current_i = g_index(carr->current_i + 1);
		nb1 = get_value(b, p1, carr, 2);
		carr->regs[b->ring[carr->current_i].code - 1] = nb1;
		b->v_params == 4 ? printf("%d r%d\n", nb1, b->ring[carr->current_i].code) : 0;
		carr->carry = carr->regs[b->ring[carr->current_i].code - 1] == 0 ? 1 : 0;
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i + 1 +\
		shift_len(p1, 4) + shift_len(p2, 4));
}

void	st(t_battle *b, t_carr *carr)//-v 4
{
	int 			reg1;
	int 			reg2;
	unsigned char	p1;
	unsigned char	p2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, NULL, b->ring[carr->current_i].code);
	if (p1 == REG && is_valid_reg(reg1 =\
	b->ring[g_index(carr->current_i + 1)].code))
	{
		b->v_params == 4 ? printf("P%5d | st ", carr->global_i) : 0;
		b->v_params == 4 ? printf("r%d ", reg1) : 0;
		if (p2 == REG && is_valid_reg(reg2 =\
		b->ring[g_index(carr->current_i + 2)].code))
		{
			b->v_params == 4 ? printf("r%d\n", reg2) : 0;
			carr->regs[reg2 - 1] = carr->regs[reg1 - 1];
		}
		else if (p2 == IND)
		{
			write_int(b, carr->regs[reg1 - 1], g_index(carr->current_i + 2 +\
			(read_short(g_index(carr->current_i + 2), b) % IDX_MOD)));
			b->v_params == 4 ? printf("%d\n",\
			read_short(g_index(carr->current_i + 2), b) % IDX_MOD) : 0;
		}
	}
	carr->current_i = g_index(carr->current_i + 1 +\
	shift_len(p1, 4) + shift_len(p2, 4));
}

void	add(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if ((b->ring[carr->current_i].code | 0b00000011u) == 0b01010111 &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 3)].code) &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 2)].code) &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 1)].code))
	{
		carr->regs[b->ring[g_index(carr->current_i + 3)].code - 1] =\
		carr->regs[b->ring[g_index(carr->current_i + 2)].code - 1] +\
		carr->regs[b->ring[g_index(carr->current_i + 1)].code - 1];
		carr->carry = carr->regs[b->ring[g_index(carr->current_i +\
		3)].code - 1] == 0 ? 1 : 0;
		b->v_params == 4 ? printf("P%5d | add r%d r%d r%d\n", carr->global_i,\
		b->ring[g_index(carr->current_i + 3)].code,\
		b->ring[g_index(carr->current_i + 2)].code,\
		b->ring[g_index(carr->current_i + 1)].code) : 0;
	}
	carr->current_i = g_index(carr->current_i	+ 1 +\
	shift_len(p1, 4) + shift_len(p2, 4) + shift_len(p3, 4));
}

void	sub(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if ((b->ring[carr->current_i].code | 0b00000011u) == 0b01010111u &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 3)].code) &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 2)].code) &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 1)].code))
	{
		carr->regs[b->ring[g_index(carr->current_i + 3)].code - 1] =\
		carr->regs[b->ring[g_index(carr->current_i + 2)].code - 1] -\
		carr->regs[b->ring[g_index(carr->current_i + 1)].code - 1];
		carr->carry = carr->regs[b->ring[g_index(carr->current_i +\
		3)].code - 1] == 0 ? 1 : 0;
		b->v_params == 4 ? printf("P%5d | sub r%d r%d r%d\n", carr->global_i,\
		b->ring[g_index(carr->current_i + 3)].code,\
		b->ring[g_index(carr->current_i + 2)].code,\
		b->ring[g_index(carr->current_i + 1)].code) : 0;
	}
	carr->current_i = g_index(carr->current_i	+ 1 +\
	shift_len(p1, 4) + shift_len(p2, 4) + shift_len(p3, 4));
}

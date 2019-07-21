/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:27:29 by smight            #+#    #+#             */
/*   Updated: 2019/07/12 16:27:31 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	and(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned int	nb1;
	unsigned int	nb2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if (p1 != T_NULL && p2 != T_NULL && p3 == REG &&\
	!(p1 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 1)].code)) &&\
	!(p2 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 2)].code)))
	{
		carr->current_i = g_index(carr->current_i + 1);
		nb1 = get_value(b, p1, carr, 2);
		nb2 = get_value(b, p2, carr, 2 + shift_len(p1, 4));
		carr->regs[b->ring[carr->current_i].code - 1] = (nb1 & nb2);
		b->v_params == 4 ? printf("P%5d | and %d %d r%d\n", carr->global_i,\
		nb1, nb2, b->ring[carr->current_i].code) : 0;
		carr->carry = carr->regs[b->ring[carr->current_i].code - 1] == 0 ? 1 : 0;
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i	+ 1 +\
		shift_len(p1, 4) + shift_len(p2, 4) + shift_len(p3, 4));
}

void	or(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned int				nb1;
	unsigned int				nb2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if (p1 != T_NULL && p2 != T_NULL && p3 == REG &&\
	!(p1 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 1)].code)) &&\
	!(p2 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 2)].code)))
	{
		carr->current_i = g_index(carr->current_i + 1);
		nb1 = get_value(b, p1, carr, 2);
		nb2 = get_value(b, p2, carr, 2 + shift_len(p1, 4));
		carr->regs[b->ring[carr->current_i].code - 1] = (nb1 | nb2);
		b->v_params == 4 ? printf("P%5d | or %d %d r%d\n", carr->global_i,\
		nb1, nb2, b->ring[carr->current_i].code) : 0;
		carr->carry = carr->regs[b->ring[carr->current_i].code - 1] == 0 ? 1 : 0;
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i	+ 1 +\
		shift_len(p1, 4) + shift_len(p2, 4) + shift_len(p3, 4));
}

void	xor(t_battle *b, t_carr *carr)//-v 4
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned int	nb1;
	unsigned int	nb2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if (p1 != T_NULL && p2 != T_NULL && p3 == REG &&\
	!(p1 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 1)].code)) &&\
	!(p2 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 2)].code)))
	{
		carr->current_i = g_index(carr->current_i + 1);
		nb1 = get_value(b, p1, carr, 2);
		nb2 = get_value(b, p2, carr, 2 + shift_len(p1, 4));
		carr->regs[b->ring[carr->current_i].code - 1] = (nb1 ^ nb2);
		b->v_params == 4 ? printf("P%5d | xor %d %d r%d\n", carr->global_i,\
		nb1, nb2, b->ring[carr->current_i].code) : 0;
		carr->carry = carr->regs[b->ring[carr->current_i].code - 1] == 0 ? 1 : 0;
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i	+ 1 +\
		shift_len(p1, 4) + shift_len(p2, 4) + shift_len(p3, 4));
}

void	zjmp(t_battle *b, t_carr *carr)//-v 4
{
	short	shift;
	carr->current_i = g_index(carr->current_i + 1);
	b->v_params == 4 ? printf("P%5d | zjmp ", carr->global_i) : 0;
	if (carr->carry == 1)
	{
		shift = read_short(carr->current_i, b);
		b->v_params == 4 ? printf("%d OK\n", shift) : 0;
		if (shift == 0)
			carr->current_i = g_index(carr->current_i - 1);
		else
			carr->current_i = g_index(carr->current_i + (shift % IDX_MOD) - 1);
	}
	else
	{
		b->v_params == 4 ? printf("%d FAILED\n", read_short(carr->current_i, b)) : 0;
		carr->current_i = g_index(carr->current_i + 2);
	}
}

void	ldi(t_battle *b, t_carr *carr)
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	int				nb1;
	int				nb2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if (p1 != T_NULL && (p2 == REG || p2 == DIR) && p3 == REG &&\
	!(p1 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 1)].code)) &&\
	!(p2 == REG && !is_valid_reg(b->ring[g_index(carr->current_i + 1 + shift_len(p1, 2))].code)) &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 1 + shift_len(p1, 2) + shift_len(p2, 2))].code))
	{
		carr->current_i = g_index(carr->current_i + 1);
		nb1 = get_value_2x(b, p1, carr, 2);
		nb2 = get_value_2x(b, p2, carr, 2 + shift_len(p1, 2));
		carr->regs[b->ring[carr->current_i].code - 1] = read_int(g_index(carr->current_i -\
		shift_len(p1, 2) - shift_len(p2, 2) - 2 + (nb1 + nb2) % IDX_MOD), b);
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i + 1 +\
		shift_len(p1, 2) + shift_len(p2, 2) + shift_len(p3, 2));
}

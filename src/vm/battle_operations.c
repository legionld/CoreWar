/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:39:19 by smight            #+#    #+#             */
/*   Updated: 2019/07/12 13:39:20 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "../../inc/vm.h"

int		 	get_value(t_battle *b, unsigned char type, t_carr *carr, int shift)
{
	int nb;

	if (type == REG)
	{
		nb = carr->regs[b->ring[g_index(carr->current_i)].code - 1];
		carr->current_i = g_index(carr->current_i + 1);
		return (nb);
	}
	else if (type == DIR)
	{
		nb = read_int(carr->current_i, b);
		carr->current_i = g_index(carr->current_i + 4);
		return (nb);
	}
	else if (type == IND)
	{
		nb = read_int(g_index(carr->current_i - shift +\
		(read_short(carr->current_i, b) % IDX_MOD)), b);
		carr->current_i = g_index(carr->current_i + 2);
		return (nb);
	}
	return (0);
}

int		get_value_2x(t_battle *b, unsigned char type, t_carr *carr, int shift)
{
	int	nb;

	if (type == REG)
	{
		nb = carr->regs[b->ring[g_index(carr->current_i)].code - 1];
		carr->current_i = g_index(carr->current_i + 1);
		return (nb);
	}
	else if (type == DIR)
	{
		nb = read_short(carr->current_i, b);
		carr->current_i = g_index(carr->current_i + 2);
		return (nb);
	}
	else if (type == IND)
	{
		nb = read_int(g_index(carr->current_i - shift +\
		(read_short(carr->current_i, b))), b);
		carr->current_i = g_index(carr->current_i + 2);
		return (nb);
	}
	return (0);
}

void			read_args(unsigned char *p1, unsigned char *p2, unsigned char *p3, unsigned char p)
{
	if (p1)
		*p1 = p | 0b00111111u;
	if (p2)
		*p2 = (p << 2) | 0b00111111;
	if (p3)
		*p3 = (p << 4) | 0b00111111;
}

void			aff(t_battle *b, t_carr *carr)
{
	carr->current_i = g_index(carr->current_i + 1);
	if ((b->ring[carr->current_i].code | 0b00111111u) == REG &&\
	is_valid_reg(b->ring[g_index(carr->current_i + 1)].code))
		//printf("aff:%c\n", (char)carr->regs[b->ring[g_index(carr->current_i)].code - 1]);
		;
	carr->current_i = g_index(carr->current_i + 2);
}

void			set_op_code(t_battle *b, t_carr *carr)
{
	carr->code_op = b->ring[g_index(carr->current_i)].code;//код записываю всегда
	if (carr->code_op >= 1 && carr->code_op <= 16)//если код корректный, то указываю циклы до операции
	{
		if (carr->code_op == 1 || carr->code_op == 4 ||\
		carr->code_op == 5 || carr->code_op == 13)
			carr->cycles_to_op = 10;
		else if (carr->code_op == 2 || carr->code_op == 3)
			carr->cycles_to_op = 5;
		else if (carr->code_op >= 6 && carr->code_op <= 8)
			carr->cycles_to_op = 6;
		else if (carr->code_op == 9)
			carr->cycles_to_op = 20;
		else if (carr->code_op == 10 || carr->code_op == 11)
			carr->cycles_to_op = 25;
		else if (carr->code_op == 12)
			carr->cycles_to_op = 800;
		else if (carr->code_op == 14)
			carr->cycles_to_op = 50;
		else if (carr->code_op == 15)
			carr->cycles_to_op = 1000;
		else if (carr->code_op == 16)
			carr->cycles_to_op = 2;
		else
			carr->cycles_to_op = 0;
	}
}

void			make_operation(t_battle *b, t_carr *carr)
{
	if (carr->code_op < 1 || carr->code_op > 16)//несуществующий код операции
		carr->current_i = g_index(carr->current_i + 1);
	else
	{
		if (b->v_params == 16)
			print_16_p(b, carr->current_i);
		b->f[carr->code_op - 1](b, carr);
	}
}

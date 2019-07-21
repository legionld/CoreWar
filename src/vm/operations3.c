/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:27:37 by smight            #+#    #+#             */
/*   Updated: 2019/07/12 16:27:40 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	sti(t_battle *b, t_carr *carr)
{
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	int				nb1;
	int				nb2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, &p3, b->ring[carr->current_i].code);
	if (p1 == REG && is_valid_reg(b->ring[g_index(carr->current_i + 1)].code) &&\
	p2 != T_NULL && !(p2 == REG &&\
	!is_valid_reg(b->ring[g_index(carr->current_i + 2)].code)) &&\
	(p3 == REG || p3 == DIR) && !(p3 == REG &&\
	!is_valid_reg(b->ring[g_index(carr->current_i + 2 + shift_len(p2, 2))].code)))
	{
		carr->current_i = g_index(carr->current_i + 2);
		nb1 = get_value_2x(b, p2, carr, 3);
		nb2 = get_value_2x(b, p3, carr, 3 + shift_len(p1, 2));
		write_int(b, carr->regs[b->ring[g_index(carr->current_i - 1 - shift_len(p2, 2) -\
		shift_len(p3, 2))].code - 1], g_index(carr->current_i - shift_len(p1, 2) -\
		shift_len(p2, 2) - shift_len(p3, 2) + 1 + (nb1 + nb2) % IDX_MOD));
	}
	else
		carr->current_i = g_index(carr->current_i + 1 +\
		shift_len(p1, 2) + shift_len(p2, 2) + shift_len(p3, 2));
}

void	fork1(t_battle *b, t_carr *carr)//-v4
{
	t_carr	*new;
	short 	shift;

	carr->current_i = g_index(carr->current_i + 1);
	b->v_params == 4 ? printf("P%5d | fork ", carr->global_i) : 0;
	if (!(new = new_carr(carr->number)))
		return ;
	new = ft_memcpy(new, carr, sizeof(t_carr));
	new->next = NULL;
	new->prev = NULL;
	shift = (get_value_2x(b, DIR, carr, 1) % IDX_MOD);
	new->current_i = g_index(carr->current_i - 3 + shift);
	b->v_params == 4 ? printf("%d (%d)\n", shift, new->current_i) : 0;
	push_carr(&b->carrs, new, b);
	b->carr_cnt++;
}

void	lld(t_battle *b, t_carr *carr)
{
	int 			reg;
	unsigned char	p1;
	unsigned char	p2;

	carr->current_i = g_index(carr->current_i + 1);
	read_args(&p1, &p2, NULL, b->ring[carr->current_i].code);
	if (p2 == REG && p1 == DIR && is_valid_reg(reg\
	= b->ring[g_index(carr->current_i + 5)].code))
	{
		carr->current_i = g_index(carr->current_i + 1);
		carr->regs[reg - 1] = read_int(carr->current_i, b);
		carr->carry = carr->regs[reg - 1] == 0 ? 1 : 0;
	}
	else if (p2 == REG && p1 == IND && is_valid_reg(reg\
	= b->ring[g_index(carr->current_i + 3)].code))
	{
		carr->current_i = g_index(carr->current_i + 1);
		carr->regs[reg - 1] = read_int(g_index(carr->current_i - 2 +\
		(read_short(carr->current_i, b))), b);
		carr->carry = carr->regs[reg - 1] == 0 ? 1 : 0;
	}
	else
		carr->current_i = g_index(carr->current_i + 1);
	carr->current_i = g_index(carr->current_i	+\
	shift_len(p1, 4) + shift_len(p2, 4));
}

void	lldi(t_battle *b, t_carr *carr)
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
		nb2 = get_value_2x(b, p2, carr, 2);
		carr->regs[b->ring[carr->current_i].code - 1] = read_int(g_index(carr->current_i -\
		shift_len(p1, 2) - shift_len(p2, 2) - 2 + nb1 + nb2), b);
		carr->carry = carr->regs[b->ring[carr->current_i].code - 1] == 0 ? 1 : 0;
		carr->current_i = g_index(carr->current_i + 1);
	}
	else
		carr->current_i = g_index(carr->current_i	+ 1 +\
		shift_len(p1, 2) + shift_len(p2, 2) + shift_len(p3, 2));
}

void	lfork(t_battle *b, t_carr *carr)
{
	t_carr	*new;

	carr->current_i = g_index(carr->current_i + 1);
	if (!(new = new_carr(carr->number)))
		return ;
	new = ft_memcpy(new, carr, sizeof(t_carr));
	new->next = NULL;
	new->prev = NULL;
	push_carr(&b->carrs, new, b);
	new->current_i = g_index(carr->current_i - 1 + get_value(b, DIR, carr, 2));
	b->carr_cnt++;
}

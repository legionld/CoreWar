/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carrs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:07:30 by smight            #+#    #+#             */
/*   Updated: 2019/07/11 11:07:34 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

int 	shift_len(unsigned char p, int t_dir_len)
{
	if (p == 0b01111111u)
		return (1);
	else if (p == 0b10111111u)
		return (t_dir_len);
	else if (p == 0b11111111u)
		return (2);
	else
		return (0);
}

int 	is_valid_reg(int nb)
{
	return (nb > 0 && nb < 17);
}

t_carr	*new_carr(int nb)
{
	t_carr	*res;

	if (!(res = ft_memalloc(sizeof(t_carr))))
		return (NULL);
	res->number = nb;
	res->regs[0] = -nb;
	return (res);
}

void	push_carr(t_carr **carrs, t_carr *new, t_battle *b)
{
	new->next = *carrs;
	b->global_i++;
	new->global_i = b->global_i;
	if (*carrs)
		(*carrs)->prev = new;
	*carrs = new;
}

void	drop_carr(t_carr **carrs, t_carr **current)//удаляет каретку и двигает current на next
{
	t_carr	*tmp;

	if (*carrs == *current)//если первый элемент
	{
		*current = (*current)->next;
		ft_memdel((void**)carrs);
		*carrs = *current;
	}
	else//если не первый элемент
	{
		tmp = *carrs;
		while (tmp && tmp->next != *current)
			tmp = tmp->next;
		if (!tmp)
			return ;
		tmp->next = (*current)->next;
		ft_memdel((void**)current);
		*current = tmp->next;
	}
}

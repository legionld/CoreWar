/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:41:25 by smight            #+#    #+#             */
/*   Updated: 2019/07/10 18:41:27 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

static int	throw_error(t_battle *b, int param)
{
	int i;

	i = -1;
	while (b->carrs && ++i < 4)
		ft_memdel((void**)&b->carrs[i]);
	ft_memdel((void**)&b);
	if (param == 1)
		printf("champion number is incorrect!\n");
	else if (param == 2)
		printf("two champions may not have the same number!\n");
	else if (param == 3)
		printf("Too many champions\n");
	return (0);
}

int 		next_index(t_battle *b)
{
	int	i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!b->champs[i])
			break ;
	}
	return (i);
}

void		cn_permutation(t_battle *b)
{
	t_champ	*tmp[MAX_PLAYERS];
	int 	i;
	int 	next;

	if (!(ft_memcpy(tmp, b->champs, sizeof(tmp))))
		return ;
	i = -1;
	while (++i < MAX_PLAYERS)
		b->champs[i] = NULL;
	i = -1;
	while (++i < MAX_PLAYERS)//заданные
		tmp[i] && tmp[i]->id != -1 ? b->champs[tmp[i]->id - 1] = tmp[i] : 0;
	i = -1;
	while (++i < MAX_PLAYERS)//не заданные
	{
		if (tmp[i] && tmp[i]->id == -1)
		{
			next = next_index(b);
			b->champs[next] = tmp[i];
			b->champs[next]->id = next;
		}
	}
}

int 		is_fail_nb(t_battle *b, int nb)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (b->champs[i] && b->champs[i]->id == nb)
			return (1);
	}
	return (0);
}

int			read_input(int c, char **v, t_battle *b)
{
	int i;
	int	j;
	int nb;

	i = 0;
	j = -1;
	b->dump_number = -1;
	while (++i < c)
	{
		nb = -1;
		if (read_flags(b, &i, v, c))
			continue ;
		if (!ft_strncmp(v[i], "-n", 2) && i + 2 < c)
		{
			nb = ft_atoi(v[++i]);
			if (nb < 1 || nb > MAX_PLAYERS || is_fail_nb(b, nb))
				return (throw_error(b, nb < 1 || nb > MAX_PLAYERS ? 1 : 2));
			i++;
		}
		if (++j > 3)
			return (throw_error(b, 3));
		if (i < c && !(b->champs[j] = read_champion(v[i], nb)))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:36:08 by smight            #+#    #+#             */
/*   Updated: 2019/07/21 22:50:26 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/render.h"

void		checkup(t_battle *b)//drop died carrs
{
	t_carr	*tmp;

	tmp = b->carrs;
	while (tmp)
	{
		if (b->cycle_count - tmp->cycle_live >= b->cycles_to_die\
		|| b->cycles_to_die <= 0)
		{
			drop_carr(&b->carrs, &tmp);
			b->carr_cnt--;
		}
		else
			tmp = tmp->next;
	}
}

void 		operations(t_battle *b)
{
	t_carr	*tmp;

	tmp = b->carrs;
	while (tmp)
	{
		if (tmp->cycles_to_op == 0)//задаю код если двигался
			set_op_code(b, tmp);
		tmp->cycles_to_op > 0 ? tmp->cycles_to_op-- : 0;//уменьшаю циклы до исполнения
		if (tmp->cycles_to_op == 0)//если дошло дело до исполнения
			make_operation(b, tmp);
		tmp = tmp->next;
	}
}

char 		*w_name(t_battle *b, int index)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = PROG_NAME_LENGTH - 1;
	while (++i < MAX_PLAYERS)
	{
		if (b->champs[i]->id == index - 1)
		{
			while (!b->champs[i]->name[j] && j > 0)
				j--;
			res = ft_strnew(j);
			ft_strncpy(res, (char*)b->champs[i]->name, j + 1);
			return (res);
		}
	}
	return (NULL);
}

void		fight(t_battle *b)
{
	int i;

	i = 0;
	while (b->carrs && (b->dump_number == -1 || b->dump_number > 0))
	{
		b->cycle_count++;
		b->v_params == 2 ? printf("It is now cycle %d\n", b->cycle_count) : 0;
		operations(b);
		viewer(b->ring);
		if (++i >= b->cycles_to_die)//каждые cycles_to_die
		{
			b->check_count++;
			checkup(b);//проверка
			if (b->last_live_cnt >= NBR_LIVE || b->check_count == MAX_CHECKS)//если проверок много или MAX_CHECKS подряд не менялось значение ctd
			{
				b->cycles_to_die -= CYCLE_DELTA;
				b->check_count = 0;//если уменьшаем ctd, то обнуляем счетчик
				b->v_params == 2 ? printf("Cycle to die is now %d\n", b->cycles_to_die) : 0;
			}
			b->last_live_cnt = 0;//zeroing live after check!
			i = 0;
		}
		b->dump_number != -1 ? b->dump_number-- : 0;
		if (b->dump_number == 1)
			printf("\n");
	}
	b->carr_cnt++;
	if (b->dump_number == 0)
		print_map(b);
	else
		printf("Contestant %d, \"%s\", has won !\n", b->last_live_player, w_name(b, b->last_live_player));
}

void		initialize_functions(t_battle *b)
{
	b->f[0] = live;
	b->f[1] = ld;
	b->f[2] = st;
	b->f[3] = add;
	b->f[4] = sub;
	b->f[5] = and;
	b->f[6] = or;
	b->f[7] = xor;
	b->f[8] = zjmp;
	b->f[9] = ldi;
	b->f[10] = sti;
	b->f[11] = fork1;
	b->f[12] = lld;
	b->f[13] = lldi;
	b->f[14] = lfork;
	b->f[15] = aff;
}

void		initialize_battle(t_battle *b)
{
	int		i;
	t_carr	*new;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (b->champs[i])
		{
			new = new_carr(b->champs[i]->id + 1);
			push_carr(&b->carrs, new, b);
		}
	}
	i = -1;
	while (++i < MAX_PLAYERS)
		if (b->champs[i])
			printf("Introducing contestants...\n* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",\
			b->champs[i]->id + 1, b->champs[i]->code_size,\
			b->champs[i]->name, b->champs[i]->comment);
	write_operations_to_ring(b);
	b->last_live = b->carrs->number;
	b->cycles_to_die = CYCLE_TO_DIE;
	b->dump_number == 0 ? b->dump_number = -1 : 0;
	initialize_functions(b);
	b->last_live_player = b->carrs->number;
}

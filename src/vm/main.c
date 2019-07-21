/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:29:53 by smight            #+#    #+#             */
/*   Updated: 2019/07/21 23:15:53 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

int 		g_index(int a)
{
	a = a % MEM_SIZE;
	if (a >= 0)
		return (a);
	return (MEM_SIZE + a);
}

static int throw_usage(void)
{
	printf("Usage: ./corewar [-dump N -v N -n N <champion1.cor> <...>\n");
	printf("    -d N      : Dumps memory after N cycles then exits\n");
	printf("    -v N      : Verbosity levels, can be added together to enable several\n"
		   "                - 0 : Show only essentials\n"
		   "                - 1 : Show lives\n"
		   "                - 2 : Show cycles\n"
		   "                - 4 : Show operations (Params are NOT litteral ...)\n"
		   "                - 8 : Show deaths\n"
		   "                - 16 : Show PC movements (Except for jumps)\n");
	printf("    -n        : set the champion number\n");
	return (0);
}

void	set_mem(t_battle *b)
{
	int i;
	
	i = -1;
	while (++i < MEM_SIZE)
	{
		b->ring[i].user = -1;
	}
	
}

int			main(int c, char **v)
{
	t_battle	*b;

	if (c <= 1)
		return (throw_usage());
	if (!(b = ft_memalloc(sizeof(t_battle))))
		return (1);
	if (!(read_input(c, v, b)))
		return (1);
	set_mem(b);
	cn_permutation(b);
	initialize_battle(b);
	fight(b);
	return (0);
}

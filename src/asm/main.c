/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:50:18 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/02 13:50:19 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		main(int c, char **v)
{
	char		*str;
	t_asm		h;
	int			fd_w;

	if (c == 1)
		return (usage());
	if (!(str = ft_read_file(v[c - 1])))
		return (cant_read_file(v[c - 1]));
	ft_header_init(&h);
	if (!ft_parse(str, &h))
		return (write(1, "Error\n", 6));
	if ((fd_w = ft_open_res_file(v[c - 1])) < 0)
		return (cant_creat_file());
	ft_write_to_file(&h, fd_w);
	close(fd_w);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_res_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:50:37 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 15:50:41 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int		ft_open_res_file(char *name)
{
	char	*res;
	int		fd;
	int		num;

	fd = -1;
	num = 0;
	while (name[++fd])
		if (name[fd] == '.')
			num = fd;
	name = ft_strndup(name, num);
	res = ft_strjoin(name, ".cor");
	ft_strdel(&name);
	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_strdel(&res);
	return (fd);
}
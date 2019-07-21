/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:51:57 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 14:51:57 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char		*ft_read_file(char *name)
{
	int		fd;
	char	*str;
	char	*buf;
	char	*tmp;

	fd = open(name, O_RDONLY);
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	if (!(buf = ft_strnew(1000000)))
		return (NULL);
	while (read(fd, buf, 1000000))
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
		ft_bzero(buf, 1000000);
	}
	close(fd);
	ft_strdel(&buf);
	return (str);
}
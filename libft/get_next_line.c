/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:50:17 by smight            #+#    #+#             */
/*   Updated: 2019/04/20 17:30:19 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_chars(char *s, int len)
{
	while (len--)
	{
		if (*s++)
			return (1);
	}
	return (0);
}

static int	ft_check_end(char *s)
{
	int res;

	res = 0;
	while (!*s)
		s++;
	while (*s && *s != '\n')
	{
		s++;
		res++;
	}
	return (res);
}

static int	ft_free_join(char **s1, char *s2)
{
	char	*res;
	int		i;
	int		mark;

	mark = 0;
	i = *s1 ? ft_strlen(*s1) : 0;
	if (!(res = ft_strnew(i + ft_check_end(s2))))
		return (1);
	if (*s1)
		res = ft_strcat(res, *s1);
	ft_strdel(s1);
	while (!*s2)
		s2++;
	while (*s2 && *s2 != '\n')
	{
		res[i++] = *s2;
		*s2++ = 0;
	}
	if (*s2 == '\n')
	{
		*s2 = 0;
		mark = 1;
	}
	*s1 = res;
	return (mark);
}

int			get_line(char **str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(*str) + 1;
	res = ft_strnew(len);
	if (!res)
		return (0);
	res = ft_strcat(res, *str);
	res[len - 1] = '\n';
	ft_strdel(str);
	*str = res;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*table[10240];
	char		*res;
	int			a;

	a = 1;
	if (BUFF_SIZE < 1 || fd < 0 || !line || fd > 10240
		|| read(fd, NULL, 0) < 0)
		return (-1);
	if (!table[fd])
		table[fd] = ft_memalloc(BUFF_SIZE + 1);
	res = NULL;
	while (1)
	{
		if (!ft_check_chars(table[fd], BUFF_SIZE))
			a = (int)read(fd, table[fd], BUFF_SIZE);
		if (a == 0 && res)
			break ;
		if (a <= 0)
			return (a);
		if (ft_free_join(&res, table[fd]) == 1 && get_line(&res))
			break ;
	}
	*line = res;
	return (1);
}

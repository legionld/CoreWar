/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:28:58 by smight            #+#    #+#             */
/*   Updated: 2019/07/08 16:29:00 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void			*free_champ(t_champ **c)
{
	if (!c || !*c)
		return (NULL);
	ft_memdel((void**)(*c)->code);
	ft_memdel((void**)(*c)->comment);
	ft_memdel((void**)c);
	return (NULL);
}

static void		*throw_error(t_champ *c, int param, char *file)
{
	if (param == 1)
		printf("Can't read source file %s\n", file);
	else if (param == 2)
		printf("Error: File %s has an invalid header\n", file);
	else if (param == 3)
		printf("Error: %s has too large a code (%d bytes > %d bytes)",\
				file ,c->code_size, CHAMP_MAX_SIZE);
	return (free_champ(&c));
}

unsigned int 			read_integer(int fd)
{
	unsigned int	sum;
	unsigned char	buff;
	unsigned int	i;

	sum = 0;
	i = 0;
	while (++i < 5)
	{
		read(fd, &buff, 1);
		sum = sum * 256 + buff;
	}
	return (sum);
}

void			read_string(int fd, t_champ *c, int param)
{
	int i;

	i = -1;
	if (param == 0)
	{
		while (++i < PROG_NAME_LENGTH)
			read(fd, &(c->name[i]), 1);
		lseek(fd, 4, SEEK_CUR);
	}
	else if (param == 1)
	{
		while (++i < COMMENT_LENGTH)
			read(fd, &(c->comment[i]), 1);
		lseek(fd, 4, SEEK_CUR);
	}
	else
	{
		while (++i < c->code_size)
			read(fd, &(c->code[i]), 1);
	}
}

t_champ			*read_champion(char *file, int id)
{
	t_champ	*c;
	int 	fd;

	fd = open(file, O_RDONLY);
	if (fd  < 0)//open file
		return (throw_error(NULL, 1, file));
	if (read_integer(fd) != COREWAR_EXEC_MAGIC)//magic header
		return (throw_error(NULL, 2, file));
	if (!(c = ft_memalloc(sizeof(t_champ))))
		return (throw_error(NULL, -1, file));
	read_string(fd, c, 0);//name+skip4b
	if ((c->code_size = read_integer(fd)) > CHAMP_MAX_SIZE)//size
		return (throw_error(c, 3, file));
	read_string(fd, c, 1);//comment+skip
	if (!(c->code = ft_memalloc(sizeof(char) * c->code_size)))
		return (free_champ(&c));
	read_string(fd, c, 3);
	close(fd);
	c->id = id;
	return (c);
}

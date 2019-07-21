/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fo_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:33:34 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/04 14:33:35 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	ft_write(char *str, int fd, int *ch)
{
	int		len;
	int		num;
	int		proc;
	int		delta;

	len = ft_strlen(str);
	proc = len % 4;
	num = len / 4;
	delta = 4 - proc;
	while (proc--)
		write(fd, "0", 1);
	str += (len % 4 ? write(fd, str, delta) : 0);
	*ch += (len % 4 ? write(fd, " ", 1) : 0);
	while (num--)
	{
		write(fd, str, 4);
		*ch += 1;
		if (*ch % 8)
			write(fd, " ", 1);
		else
			write(fd, "\n", 1);
		str += 4;
	}
}

static void	ft_write_str(char *str, int fd, int *num, int len)
{
	char	*res;
	char	*tmp2;
	char	*tmp;
	int		i;

	i = -1;
	res = NULL;
	while (++i < len)
	{
		tmp = res;
		tmp2 = ft_itoa_base(str[i], 16);
		res = ft_strjoin(res, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (i % 2 != 0)
	{
		tmp = res;
		res = ft_strjoin(res, "00");
		ft_strdel(&tmp);
	}
	ft_write(res, fd, num);
}

static void	ft_write_mew(char *str, int fd, int *num)
{
	int		len;
	char	*tmp;

	len = 8 - ft_strlen(str);
	while (len--)
	{
		tmp = str;
		str = ft_strjoin("0", str);
		ft_strdel(&tmp);
	}
	ft_write(str, fd, num);
}

void		ft_write_to_file(t_asm *h, int fd)
{
	char		*str;
	int			num;

	num = 0;
//	str = ft_itoa_base(h->magic, 16);
//	ft_write(str, fd, &num);
//	ft_strdel(&str);
//	ft_write_str(h->prog_name, fd, &num, PROG_NAME_LENGTH);
//	ft_write("00000000", fd, &num);
//	//exec_llala
//	ft_write_str(h->comment, fd, &num, COMMENT_LENGTH);
//	str = ft_itoa_base(CHAMP_MAX_SIZE, 16);
//	ft_write_mew(str, fd, &num);
//	ft_write("00000000", fd, &num);
}
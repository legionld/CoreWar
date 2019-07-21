/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:08:53 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 16:08:58 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char		*ft_command(char *str, t_asm *h, int *c, int *r)
{
	int i;

	if (!ft_strcmp_space(str, COMMENT_CMD_STRING))
	{
		if (h->was_comment)
			return (NULL);
		h->was_comment = 1;
		str += 8;
		str = ft_skip_whitespaces(str, c);
		i = -1;
		if (*str == '"')
			str++;
		else
			return (NULL);
		while (*str && *str != '"' && ++i <= COMMENT_LENGTH)
		{
			h->comment[i] = *str;
			str++;
		}
		if (*str == '"')
			str++;
		else
			return (too_long_comment());
		return (str);
	}
	else if (!ft_strcmp_space(str, NAME_CMD_STRING))
	{
		if (h->was_name)
			return (NULL);
		h->was_name = 1;
		str += 5;
		str = ft_skip_whitespaces(str, c);
		i = -1;
		if (*str == '"')
			str++;
		else
			return (NULL);
		while (*str && *str != '"' && ++i <= PROG_NAME_LENGTH)
		{
			h->prog_name[i] = *str;
			str++;
		}
		if (*str == '"')
			str++;
		else
			return (too_long_name());
		return (ft_skip_whitespaces(str, c));
	}
	else
		return (NULL);
}

int			ft_parse(char *str, t_asm *h)
{
	int		c;
	int		r;

	r = 1;
	while (*str)
	{
		c = 1;
		str = ft_skip_whitespaces(str, &c);
		if (*str == COMMENT_CHAR || *str == ';')
			str = ft_skip_until_slashn(str);
		else if (*str == '.')
		{
			if (!(str = ft_command(str, h, &c, &r)))
				return (0);
		}
		*str ? str++ : NULL;
	}
	return (1);
}
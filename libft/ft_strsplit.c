/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:42:41 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:54:00 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int res;
	int mark;

	res = 0;
	mark = 0;
	while (*s != '\0')
	{
		if (*s != c && !mark)
		{
			mark = 1;
			res++;
		}
		else if (*s == c)
			mark = 0;
		s++;
	}
	return (res);
}

static int	ft_word_len(char *s, char c)
{
	int res;

	res = 1;
	while (*s != c && *s != '\0')
	{
		s++;
		res++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if ((temp = (char**)malloc(8 * (ft_word_count((char*)s, c) + 1))))
	{
		while (*s != '\0')
		{
			if ((char)*s != c)
			{
				j = 0;
				if (!(temp[i] = (char*)malloc(ft_word_len((char*)s, c))))
					return (ft_clear_table(temp, i));
				while ((char)*s != c && *s != '\0')
					temp[i][j++] = *s++;
				temp[i++][j] = '\0';
			}
			s = ((char)*s == c && (char)*s != '\0' ? ++s : s);
		}
		temp[i] = 0;
	}
	return (&temp[0]);
}

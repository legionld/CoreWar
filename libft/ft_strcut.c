/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:41:02 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/14 12:35:43 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *line2, char c)
{
	int		iter;
	char	*line3;
	char	*tmp;

	iter = 0;
	line3 = NULL;
	tmp = line2;
	while (tmp[iter] != c && tmp[iter])
		iter++;
	if (tmp[iter] == c)
		line3 = ft_strndup(tmp, iter);
	else
		line3 = ft_strdup(tmp);
	return (line3);
}

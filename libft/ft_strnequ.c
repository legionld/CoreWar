/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:41 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:23:59 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_endnull(const char *c)
{
	return (!c || *c == '\0' ? 1 : 0);
}

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = (int)n;
	if ((ft_is_endnull(s1) && ft_is_endnull(s2)) || n == 0)
		return (1);
	if ((!s1 && s2) || (!s2 && s1))
		return (0);
	while (i-- && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (i >= 0 ? 0 : 1);
}

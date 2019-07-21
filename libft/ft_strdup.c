/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:26:54 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:07:29 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(s1);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res)
	{
		while (++i < len)
			res[i] = s1[i];
		res[i] = '\0';
	}
	return (res);
}

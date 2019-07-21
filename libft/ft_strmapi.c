/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:03:30 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:22:39 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (res)
		{
			while (i < len)
			{
				res[i] = f((unsigned int)i, (char)s[i]);
				i++;
			}
			res[i] = '\0';
		}
		return (res);
	}
	return (NULL);
}

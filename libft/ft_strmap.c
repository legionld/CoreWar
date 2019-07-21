/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:42:45 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:22:19 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*temp;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		res = (char*)malloc(sizeof(char) * (len + 1));
		temp = res;
		if (res)
		{
			while (len--)
				*temp++ = f((char)*s++);
			*temp = '\0';
		}
		return (res);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:42:45 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 22:44:55 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[i]);
	while (haystack[i] != '\0' && i < (int)len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] != '\0' && haystack[i + j] != '\0'
					&& i + j < (int)len)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

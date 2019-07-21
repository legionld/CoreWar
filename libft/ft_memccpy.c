/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:01:29 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:05:26 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*s1;
	unsigned char		*s2;

	s1 = src;
	s2 = dst;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
		{
			*s2 = *s1;
			s2++;
			return ((void*)s2);
		}
		*s2++ = *s1++;
	}
	return (NULL);
}

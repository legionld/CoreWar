/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:49:38 by smight            #+#    #+#             */
/*   Updated: 2019/05/13 15:55:25 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s1;
	unsigned char		*s2;

	s1 = src;
	s2 = dst;
	if (!dst || !src)
		return (NULL);
	while (n--)
		*s2++ = *s1++;
	return (dst);
}

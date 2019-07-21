/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:26:54 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:05:54 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_go_end(unsigned char *a, size_t len)
{
	int i;

	i = 0;
	while (++i < (int)len)
		a++;
	return (a);
}

static	void	*ft_reverse_memcpy(void *dst,
									const void *src, size_t n)
{
	unsigned const char	*s1;
	unsigned char		*s2;

	s1 = src;
	s2 = dst;
	while (n--)
		*s2-- = *s1--;
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	d = dst;
	s = (unsigned char*)src;
	if (dst < src)
		ft_memcpy(d, s, len);
	else
	{
		d = ft_go_end(d, len);
		s = ft_go_end(s, len);
		ft_reverse_memcpy(d, s, len);
	}
	return (dst);
}

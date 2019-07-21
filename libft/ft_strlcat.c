/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:26:54 by smight            #+#    #+#             */
/*   Updated: 2019/04/09 14:47:14 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	i;

	i = 0;
	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (ld > size)
		return (ls + size);
	i = ld;
	while (*src != '\0' && size > i + 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (ld + ls);
}

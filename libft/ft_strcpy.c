/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:26:54 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 11:49:53 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcpy(char *dst, const char *src)
{
	int len;
	int i;

	i = -1;
	len = (int)ft_strlen(src);
	while (++i < len)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}

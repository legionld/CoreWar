/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:48:53 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 11:49:05 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < (int)n)
	{
		if (str1[i] != str2[i])
			return ((str1[i] == '\0' ? 0 : str1[i]) -
					(str2[i] == '\0' ? 0 : str2[i]));
			i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:10:52 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:56:33 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 != '\0' && *str2 != '\0' && n)
	{
		if (*str1 != *str2)
		{
			return ((*str1 == '\0' ? 0 : (int)*str1) -
					(*str2 == '\0' ? 0 : (int)*str2));
		}
		str1++;
		str2++;
		n--;
	}
	if (n <= 0)
		return (0);
	return ((*str1 == '\0' ? 0 : (int)*str1) -
				(*str2 == '\0' ? 0 : (int)*str2));
}

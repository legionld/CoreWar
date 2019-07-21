/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:48:32 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 23:09:29 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return ((*str1 == '\0' ? 0 : (int)*str1) -
					(*str2 == '\0' ? 0 : (int)*str2));
		}
		str1++;
		str2++;
	}
	return ((*str1 == '\0' ? 0 : (int)*str1) -
			(*str2 == '\0' ? 0 : (int)*str2));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:26:54 by smight            #+#    #+#             */
/*   Updated: 2019/04/08 19:18:37 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2,
																size_t n)
{
	char *str1;
	char *str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0' && n--)
		*str1++ = *str2++;
	*str1 = '\0';
	return (s1);
}

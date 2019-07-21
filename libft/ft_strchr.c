/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:12:18 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 21:17:18 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *temp;

	temp = (char*)s;
	while (*temp != '\0')
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
	}
	return (*temp == (unsigned char)c ? temp : NULL);
}

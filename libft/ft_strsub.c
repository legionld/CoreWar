/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:34:43 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:24:33 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;
	char *temp;

	if (!s || len == 0)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	temp = res;
	if (res)
	{
		while (start--)
			s++;
		while (len--)
			*temp++ = *s++;
		*temp = '\0';
	}
	return (res);
}

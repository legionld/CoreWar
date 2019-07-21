/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:19:34 by smight            #+#    #+#             */
/*   Updated: 2019/05/13 15:54:45 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;
	char *temp;

	if (size > size + 1)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (size + 1));
	temp = res;
	if (res)
	{
		while (size--)
			*temp++ = 0;
		*temp = 0;
	}
	return (res);
}

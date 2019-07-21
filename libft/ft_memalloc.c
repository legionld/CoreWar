/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:06:46 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:20:08 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *res;
	char *temp;

	res = NULL;
	res = (char*)malloc(sizeof(char) * size);
	temp = res;
	if (res)
		while (size--)
			*temp++ = 0;
	return ((void*)res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:39:19 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:21:56 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = s;
	if (s && f)
	{
		while (temp[i] != '\0')
		{
			f(i, &temp[i]);
			i++;
		}
	}
}

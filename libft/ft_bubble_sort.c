/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:36:25 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 01:51:09 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_bubble_sort(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < ft_strlen(str))
	{
		j = 0;
		while (j < ft_strlen(str))
		{
			if (str[i] < str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

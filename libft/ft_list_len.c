/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:26:41 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 01:49:48 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_len(t_list *alst)
{
	size_t	res;

	res = 0;
	if (alst)
		while (alst)
		{
			res++;
			alst = alst->next;
		}
	return (res);
}

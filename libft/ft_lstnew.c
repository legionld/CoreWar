/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:45:49 by smight            #+#    #+#             */
/*   Updated: 2019/05/13 15:37:31 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res)
	{
		if (content && content_size > 0)
		{
			res->content = ft_memalloc(content_size);
			if (!res->content)
			{
				ft_memdel((void**)&res);
				return (NULL);
			}
			ft_memcpy(res->content, content, content_size);
			res->content_size = content_size;
		}
		else
		{
			res->content = NULL;
			res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}

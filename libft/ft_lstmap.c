/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:59:34 by smight            #+#    #+#             */
/*   Updated: 2019/05/13 15:52:10 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_memdel((void **)&lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*first;

	temp = ft_lstnew(lst->content, lst->content_size);
	if (!temp)
		return (NULL);
	temp = (*f)(temp);
	first = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = ft_lstnew(lst->content, lst->content_size);
		if (temp->next == NULL)
		{
			ft_clear_list(first);
			return (NULL);
		}
		temp->next = (*f)(temp->next);
		temp = temp->next;
	}
	return (first);
}

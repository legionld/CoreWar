/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:18:17 by smight            #+#    #+#             */
/*   Updated: 2019/04/06 21:23:35 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *temp;
	char *res;

	temp = (char*)s;
	res = (*temp == (unsigned char)c ? temp : NULL);
	while (*temp++ != '\0')
		if (*temp == (unsigned char)c)
			res = temp;
	return (res);
}

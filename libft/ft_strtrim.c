/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:26:51 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 01:19:20 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace_s(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ? 1 : 0);
}

static size_t	ft_trim_len(char const *s)
{
	size_t i;
	size_t end;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while (ft_isspace_s(s[i]) && i > 0)
		i--;
	end = i;
	i = 0;
	while (s[i] != '\0' && ft_isspace_s(s[i]) == 1)
		i++;
	return (end != 0 ? end - i + 1 : 0);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	char	*temp;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_trim_len(s);
	res = (char*)malloc(sizeof(char) * (len + 1));
	temp = res;
	if (temp)
	{
		while (ft_isspace_s(*s) == 1)
			s++;
		while (len--)
			*temp++ = (char)*s++;
		*temp = '\0';
	}
	return (res);
}

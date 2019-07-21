/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:38:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 16:38:46 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char		*ft_skip_until_slashn(char *str)
{
	while (*str && *str != '\n')
		str++;
	return (str);
}

char		*ft_skip_whitespaces(char *str, int *c)
{
	while (*str && (*str == ' ' || *str == '\t'))
	{
		if (*str == ' ')
			*c += 1;
		else if (*str == '\t')
			*c += 4;
		else
			break;
		str++;
	}
	return (str);
}

int			ft_strcmp_space(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return ((!*str1 ? 0 : (int)*str1) -
					(!*str2 ? 0 : (int)*str2));
		}
		str1++;
		str2++;
	}
	if (!*str2 && (*str1 == ' ' || *str1 == '\t'))
		return (0);
	return (1);

}
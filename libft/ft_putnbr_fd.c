/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:50:43 by smight            #+#    #+#             */
/*   Updated: 2019/04/08 17:00:26 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int num;

	num = (long int)n;
	if (fd != -1)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num *= -1;
		}
		if (num < 10)
			ft_putchar_fd(num + '0', fd);
		else
		{
			ft_putnbr_fd(num / 10, fd);
			ft_putnbr_fd(num % 10, fd);
		}
	}
}

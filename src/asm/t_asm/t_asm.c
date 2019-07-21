/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:45:36 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 16:45:37 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void		ft_header_init(t_asm *h)
{
	ft_bzero(h->comment, COMMENT_LENGTH);
	ft_bzero(h->prog_name, PROG_NAME_LENGTH);
	h->was_comment = 0;
	h->was_name = 0;
	h->magic = COREWAR_EXEC_MAGIC;
}
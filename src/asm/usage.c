/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:20:33 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/03 15:20:34 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"
#include <stdio.h> //delete

int		usage(void)
{
	write(1, "Usage: ./asm [-a] <sourcefile.s>\n", 33);
	write(1, "\t-a : Instead of creating a /.cor file, outputs a stripped", 58);
	write(1, " and annotated version of the code to the standard output\n", 58);
	return (1);
}

char	*lexical_error(int c, int r)
{
	printf("Lexical error at [%zd:%zd]\n", r, c); //ft
	return (NULL);
}

char	*too_long_comment()
{
	printf("Champion comment too long (Max length %d)\n", COMMENT_LENGTH); //ft
}

char	*too_long_name()
{
	printf("Champion name too long (Max length %d)\n", PROG_NAME_LENGTH); //ft
}

int		cant_creat_file(void)
{
	write(1, "Error: can't create output file\n", 32);
	return (1);
}

int		cant_read_file(char *name)
{
	write(1, "Can't read source file ", 23);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
	return (1);
}

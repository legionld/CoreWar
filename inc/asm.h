/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:55:48 by djeanna           #+#    #+#             */
/*   Updated: 2019/07/02 13:55:50 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ASM_H
# define COREWAR_ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "op.h"

int					ft_printf(char *str, ...);

typedef struct		s_asm
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	int				was_name;
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	int				was_comment;
}					t_asm;

/*
**		To write error messages
*/

int					usage(void);
int					cant_creat_file(void);
int					cant_read_file(char *name);
char				*lexical_error(int c, int r);
char				*too_long_name();
char				*too_long_comment();

/*
**		To read given file
**/

char				*ft_read_file(char *name);
int					ft_open_res_file(char *name);

int					ft_parse(char *str, t_asm *h);
char				*ft_skip_until_slashn(char *str);
int					ft_strcmp_space(char *str1, char *str2);
char				*ft_skip_whitespaces(char *str, int *c);

void				ft_header_init(t_asm *h);

char				*ft_itoa_base(uintmax_t n, int base);
void				ft_write_to_file(t_asm *h, int fd);
#endif

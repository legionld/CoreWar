/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:30:40 by smight            #+#    #+#             */
/*   Updated: 2019/07/21 23:01:16 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "op.h"
# include "stdio.h"

# define BUFF_SIZE_U 1144
# define FUNC_CNT 16
# define REG 0b1111111
# define DIR 0b10111111
# define IND 0b11111111
# define T_NULL 0b111111

typedef struct		s_champ
{
	char			id;
	unsigned char	name[PROG_NAME_LENGTH];
	unsigned char	comment[COMMENT_LENGTH];
	unsigned int	code_size;
	unsigned char	*code;
}					t_champ;

typedef struct		s_carr
{
	int				current_i;
	int 			global_i;
	unsigned char	number;
	unsigned char	carry;
	unsigned char	code_op;
	unsigned int	cycle_live;
	unsigned int	cycles_to_op;
	size_t 			current;
	size_t			step_bytes;
	int				regs[REG_NUMBER];
	struct s_carr	*next;
	struct s_carr	*prev;
}					t_carr;

typedef struct		s_ring
{
	unsigned char	code;
	char            user;
}					t_ring;

typedef struct		s_battle
{
	int				dump_number;
	int				global_i;
	int				last_live;//по нему определяю победителя
	int 			last_live_player;
	int				carr_cnt;
	int				cycle_count;
	int				last_live_cnt;
	int				cycles_to_die;
	int				check_count;
	char 			v_params;
	int				max_c_number;
	t_champ			*champs[MAX_PLAYERS];
	t_carr			*carrs;
	t_ring			ring[MEM_SIZE];//ТУТ ЖИВЕТ ВСЕ ПОЛЕ
	void			(*f[FUNC_CNT])(struct s_battle *b, t_carr *carr);
}					t_battle;

t_champ				*read_champion(char *file, int id);
void				cn_permutation(t_battle *b);
void				print_champion(int fd);
void				push_champ(t_champ **start, t_champ *new);
int					read_input(int c, char **v, t_battle *b);
void				initialize_battle(t_battle *b);
void				push_carr(t_carr **carrs, t_carr *new, t_battle *b);
t_carr				*new_carr(int nb);
void				drop_carr(t_carr **carrs, t_carr **current);
void				write_operations_to_ring(t_battle *b);
void				fight(t_battle *b);
void				set_op_code(t_battle *b, t_carr *carr);
void				make_operation(t_battle *b, t_carr *carr);
char		 		*w_name(t_battle *b, int index);

/***  OPERATIONS!!  ***/
void				live(t_battle *b, t_carr *carr);
void				ld(t_battle *b, t_carr *carr);
void				st(t_battle *b, t_carr *carr);
void				add(t_battle *b, t_carr *carr);
void				sub(t_battle *b, t_carr *carr);
void				and(t_battle *b, t_carr *carr);
void				or(t_battle *b, t_carr *carr);
void				xor(t_battle *b, t_carr *carr);
void				zjmp(t_battle *b, t_carr *carr);
void				ldi(t_battle *b, t_carr *carr);
void				sti(t_battle *b, t_carr *carr);
void				fork1(t_battle *b, t_carr *carr);
void				lld(t_battle *b, t_carr *carr);
void				lldi(t_battle *b, t_carr *carr);
void				lfork(t_battle *b, t_carr *carr);
void				aff(t_battle *b, t_carr *carr);
/***  OPERATIONS!!  ***/
unsigned int		read_int(int start_i, t_battle *b);
void				write_int(t_battle *b, unsigned int nb, int start_i);
short				read_short(int start_i, t_battle *b);
int				 	shift_len(unsigned char p, int t_dir_len);
int 				is_valid_reg(int nb);
void				print_map(t_battle *b);
void				read_args(unsigned char *p1, unsigned char *p2, unsigned char *p3, unsigned char p);
int					get_value(t_battle *b, unsigned char type, t_carr *carr, int t_dir_size);
int					get_value_2x(t_battle *b, unsigned char type, t_carr *carr, int number);
int			 		g_index(int a);

/**		FLAGS	**/
int				 	read_flags(t_battle *b, int *i, char **v, int c);
void				print_16_p(t_battle	*b, int c_index);
char			 	*op_name(unsigned char code);
/**		FLAGS	**/

#endif

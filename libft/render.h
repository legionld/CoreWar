/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:52:51 by jschille          #+#    #+#             */
/*   Updated: 2019/07/21 14:22:18 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <ncurses.h>
# include <stdlib.h>
# include <string.h>
# include "images.h"

# define WIN_ARENA_W 196
# define WIN_ARENA_H 66
# define WIN_INFO_W 196
# define WIN_INFO_H 13
# define WIN_LOGO_W 102
# define WIN_LOGO_H 13
# define WIN_PROC_W 102
# define WIN_PROC_H 53
# define WIN_PLAYERS_W 102
# define WIN_PLAYERS_H 13

typedef struct  s_winds
{
    WINDOW *arena;
    WINDOW *logo;
    WINDOW *proc;
    WINDOW *players;
    WINDOW *info;
}               t_winds;

typedef struct  s_ring
{
    unsigned char   code;
    char            user;
    char            carry;
}               t_ring;

/*
**							*
**			CREATOR			*
**							*
*/

t_winds			*create_win();
t_winds			*create_sub_win();

int		viewer(t_ring **ring);
int		err_out(int e, t_winds **mw, t_winds **sw);


#endif
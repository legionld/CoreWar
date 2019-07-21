/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:10:32 by jschille          #+#    #+#             */
/*   Updated: 2019/07/21 22:34:49 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

static void	create_headers(t_winds *win)
{
	mvwprintw(win->arena, 0, WIN_ARENA_W / 2 - 4, " -ARENA- ");
	mvwprintw(win->info, 0, WIN_INFO_W / 2 - 4, " -INFO- ");
	mvwprintw(win->logo, 0, WIN_LOGO_W / 2 - 4, " -LOGO- ");
	mvwprintw(win->proc, 0, WIN_PROC_W / 2 - 6, " -PROCESSUS- ");
	mvwprintw(win->players, 0, WIN_PLAYERS_W / 2 - 6, " -PLAYERS- ");
}

static WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

t_winds		*create_win()
{
	t_winds *winds;
	int		h_arena;

	h_arena = LINES/7*6;

	if (!(winds = (t_winds*)malloc(sizeof(t_winds))))
		return (NULL);
	winds->arena = create_newwin(WIN_ARENA_H, WIN_ARENA_W, 0, 0);
	winds->info = create_newwin(WIN_INFO_H, WIN_INFO_W, WIN_ARENA_H, 0);
	winds->logo = create_newwin(WIN_LOGO_H, WIN_LOGO_W, 0, WIN_ARENA_W + 1);
	winds->proc = create_newwin(WIN_PROC_H, WIN_PROC_W, WIN_LOGO_H, WIN_ARENA_W + 1);
	winds->players = create_newwin(WIN_PLAYERS_H, WIN_PLAYERS_W, WIN_PROC_H + WIN_LOGO_H, WIN_ARENA_W + 1);
	create_headers(winds);
	// winds->arena = create_newwin(h_arena, COLS/3*2, 0, 0);
	// winds->info = create_newwin(WIN_INFO_H, WIN_INFO_W, h_arena, 0);
	// winds->logo = create_newwin(WIN_LOGO_H, WIN_LOGO_W, 0, COLS/3*2 + 1);
	// winds->proc = create_newwin(WIN_PROC_H, WIN_PROC_W, WIN_LOGO_H, COLS/3*2 + 1);
	// winds->players = create_newwin(WIN_PLAYERS_H, WIN_PLAYERS_W, WIN_PROC_H + WIN_LOGO_H, COLS/3*2 + 1);
	// create_headers(winds);
	return (winds);
}

t_winds		*create_sub_win()
{
	t_winds *winds;

	if (!(winds = (t_winds*)malloc(sizeof(t_winds))))
		return (NULL);
	winds->arena = create_newwin(WIN_ARENA_H - 2, WIN_ARENA_W - 2, 1, 1);
	winds->info = create_newwin(WIN_INFO_H - 2, WIN_INFO_W - 2, WIN_ARENA_H + 1, 1);
	winds->logo = create_newwin(WIN_LOGO_H - 2, WIN_LOGO_W - 2, 1, WIN_ARENA_W + 2);
	winds->proc = create_newwin(WIN_PROC_H - 2, WIN_PROC_W - 2, WIN_LOGO_H + 1, WIN_ARENA_W + 2);
	winds->players = create_newwin(WIN_PLAYERS_H - 2, WIN_PLAYERS_W - 2, WIN_PROC_H + WIN_LOGO_H + 1, WIN_ARENA_W + 2);
	//drawable(winds);
	return (winds);
}

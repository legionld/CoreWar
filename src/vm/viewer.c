/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:48:08 by jschille          #+#    #+#             */
/*   Updated: 2019/07/21 23:18:31 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"
#include "../../inc/vm.h"

void	update_win(t_winds *winds)
{
	wrefresh(winds->arena);
	wrefresh(winds->info);
	wrefresh(winds->logo);
	wrefresh(winds->proc);
	wrefresh(winds->players);
}

void	fill_win(t_winds *win, t_ring *ring)
{
	int		i;
	int		j;
	int		d;
	char	*clr;
	
	i = -1;
	while (++i < 64)
	{
		j = -1;
		d = 1;
		while (++j < 64)
		{
			//wattron(win->arena, A_BOLD);
			wattron(win->arena, COLOR_PAIR(ring[i * 63 + j].user + 1));
			mvwprintw(win->arena, i + 1, j+d + 2, "%02x", ring[i * 63 + j].code);
			wattroff(win->arena, COLOR_PAIR(ring[i * 63 + j].user + 1));
			//wattroff(win->arena, A_BOLD);
			d += 2;
		}
		
	}
	update_win(win);
}

int		viewer(t_ring *ring)
{
	setlocale(0, "");
	t_winds *winds;
	t_winds	*sub_win;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	
	refresh();
	winds = create_win();
	//sub_win = create_sub_win();
	if (winds == NULL || sub_win == NULL)
		return (err_out(1, &winds, &sub_win));
	update_win(winds);
	//update_win(sub_win);
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(6, COLOR_CYAN, COLOR_WHITE);
	init_pair(7, COLOR_CYAN, COLOR_MAGENTA);
	init_pair(8, COLOR_CYAN, COLOR_MAGENTA);
	fill_win(winds, ring);
	//sleep(1);
	if ((ch = getch()) == 'q')
	{	
		endwin();
		exit(0);
	}
	
	endwin();			/* End curses mode		  */
	
	return 0;
}
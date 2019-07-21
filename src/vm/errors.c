/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:55:48 by jschille          #+#    #+#             */
/*   Updated: 2019/07/21 22:34:53 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

int		err_out(int e, t_winds **mw, t_winds **sw)
{
	if (mw && *mw)
	{
		destroy_win((*mw)->arena);
		destroy_win((*mw)->logo);
		destroy_win((*mw)->proc);
		destroy_win((*mw)->players);
		destroy_win((*mw)->info);
		free(*mw);
	}
	if (sw && *sw)
	{
		destroy_win((*sw)->arena);
		destroy_win((*sw)->logo);
		destroy_win((*sw)->proc);
		destroy_win((*sw)->players);
		destroy_win((*sw)->info);
		free(*sw);
	}
	return (-1);
}
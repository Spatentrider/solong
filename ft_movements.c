/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:33:26 by jzhou             #+#    #+#             */
/*   Updated: 2022/11/14 17:08:52 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"
#include <stdio.h>

void	ft_w(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;
	
	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight - 1][jwidth] == '0'
		|| mygame->map.map[iheight - 1][jwidth] == 'C'
		|| mygame->map.map[iheight - 1][jwidth] == '1')
	{
		if (mygame->map.map[iheight - 1][jwidth] == 'C')
			ft_countcol(mygame);
		else if (mygame->map.map[iheight - 1][jwidth] == '1')
			ft_paintpath(jwidth, iheight, mygame);	
		mygame->myplayer.vertical--;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
	else if (mygame->map.map[iheight - 1][jwidth] == 'E')
	{
		mygame->myplayer.vertical--;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		ft_checkcol(mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
}

void	ft_a(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight][jwidth - 1] == '0'
		|| mygame->map.map[iheight][jwidth - 1] == 'C'
		|| mygame->map.map[iheight][jwidth - 1] == '1')
	{
		if (mygame->map.map[iheight][jwidth - 1] == 'C')
			ft_countcol(mygame);
		else if (mygame->map.map[iheight][jwidth - 1] == '1' && mygame->map.map[iheight][jwidth - 1] != mygame->map.map[0][0])
			ft_paintpath(jwidth, iheight, mygame);
		mygame->myplayer.horizontal--;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
	else if (mygame->map.map[iheight][jwidth - 1] == 'E')
	{
		mygame->myplayer.horizontal--;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		ft_checkcol(mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
}

void	ft_s(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight + 1][jwidth] == '0'
		|| mygame->map.map[iheight + 1][jwidth] == 'C'
		|| mygame->map.map[iheight + 1][jwidth] == '1')
	{
		if (mygame->map.map[iheight + 1][jwidth] == 'C')
			ft_countcol(mygame);
		else if (mygame->map.map[iheight + 1][jwidth] == '1')
			ft_paintpath(jwidth, iheight, mygame);
		mygame->myplayer.vertical++;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
	else if (mygame->map.map[iheight + 1][jwidth] == 'E')
	{
		mygame->myplayer.vertical++;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		ft_checkcol(mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
}

void	ft_d(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight][jwidth + 1] == '0'
		|| mygame->map.map[iheight][jwidth + 1] == 'C'
		|| mygame->map.map[iheight][jwidth + 1] == '1')
	{
		if (mygame->map.map[iheight][jwidth + 1] == 'C')
			ft_countcol(mygame);
		else if (mygame->map.map[iheight][jwidth + 1] == '1')
			ft_paintpath(jwidth, iheight, mygame);
		mygame->myplayer.horizontal++;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
	else if (mygame->map.map[iheight][jwidth + 1] == 'E')
	{
		mygame->myplayer.horizontal++;
		ft_updatemap(jwidth, iheight, mygame);
		ft_currentfield(jwidth, iheight, mygame);
		ft_checkcol(mygame);
		mygame->steps++;
		printf("Steps taken: %d\n", mygame->steps);
	}
}

int	ft_playermove(int keycode, t_so_long *mygame)
{
	if (keycode == 13)
		ft_w(mygame);
	if (keycode == 0)
		ft_a(mygame);
	if (keycode == 1)
		ft_s(mygame);
	if (keycode == 2)
		ft_d(mygame);
	if (keycode == 53)
		ft_exitgame();
	return (0);
}
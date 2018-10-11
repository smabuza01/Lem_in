/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabuza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:13:44 by smabuza           #+#    #+#             */
/*   Updated: 2018/08/24 08:06:46 by smabuza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		check_piece(int change_dir, char **piece, t_list mvar, t_list pvar)
{
	int		flag;
	int		x;
	int		y;

	x = 0;
	flag = 0;
	if (change_dir != 1)
		return (0);
	while (x < pvar.hgt && flag == 0)
	{
		y = 0;
		while (y < pvar.wdt && flag == 0)
		{
			if (piece[x][y] == '*' &&
				((mvar.x + x) >= mvar.hgt ||
				(mvar.y + y) >= mvar.wdt + 1))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		valid_move(char **map, char **piece, t_list mvar, t_list pvar)
{
	int change_dir;

	change_dir = 0;
	pvar.x = 0;
	while (pvar.x < pvar.hgt && change_dir <= 1)
	{
		pvar.y = 0;
		while (pvar.y < pvar.wdt && change_dir <= 1)
		{
			if ((piece[pvar.x][pvar.y] == '*') &&
				((mvar.x + pvar.x) >= 0 && (mvar.x + pvar.x) < mvar.hgt) &&
				((mvar.y + pvar.y) >= 0 && (mvar.y + pvar.y) < mvar.wdt))
			{
				if (map[mvar.x + pvar.x][mvar.y + pvar.y] == ft_toupper(pvar.hy)
					|| map[mvar.x + pvar.x][mvar.y + pvar.y] == pvar.hy)
					return (-1);
				if (map[mvar.x + pvar.x][mvar.y + pvar.y] == ft_toupper(pvar.hx)
					|| map[mvar.x + pvar.x][mvar.y + pvar.y] == pvar.hx)
					change_dir++;
			}
			pvar.y++;
		}
		pvar.x++;
	}
	return (check_piece(change_dir, piece, mvar, pvar));
}

int		output(int x, int y, int checker)
{
	if (checker > 0)
	{
		ft_putnbr(x);
		ft_putstr(" ");
		ft_putnbr(y);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int		check_move(char **map, char **piece, t_list mvar, t_list pvar)
{
	int		checker;

	checker = 0;
	mvar.hx = 0;
	mvar.hy = 0;
	mvar.x = 0;
	while (mvar.x < mvar.hgt && checker == 0)
	{
		mvar.y = 0;
		while (mvar.x < mvar.hgt && mvar.y < mvar.wdt && checker == 0)
		{
			if (valid_move(map, piece, mvar, pvar) == 1)
			{
				mvar.hx = mvar.x;
				mvar.hy = mvar.y;
				checker++;
			}
			mvar.y++;
		}
		mvar.x++;
	}
	return (output(mvar.hx, mvar.hy, checker));
}

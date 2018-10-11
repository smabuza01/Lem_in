/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabuza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:43:11 by smabuza           #+#    #+#             */
/*   Updated: 2018/08/24 08:01:01 by smabuza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		main(void)
{
	char	**map;
	char	**piece;
	t_list	mvar;
	t_list	pvar;

	get_player_num(&pvar.hx, &pvar.hy);
	read_input(&mvar.hgt, &mvar.wdt);
	map = data_map(mvar.hgt, mvar.wdt);
	read_input(&pvar.hgt, &pvar.wdt);
	piece = data_piece(pvar.hgt, pvar.wdt);
	while (check_move(map, piece, mvar, pvar) == 1)
	{
		read_input(&mvar.hgt, &mvar.wdt);
		map = data_map(mvar.hgt, mvar.wdt);
		read_input(&pvar.hgt, &pvar.wdt);
		piece = data_piece(pvar.hgt, pvar.wdt);
	}
	output(0, 0, 1);
	return (0);
}

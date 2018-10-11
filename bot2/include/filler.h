/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabuza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:31:10 by smabuza           #+#    #+#             */
/*   Updated: 2018/08/24 08:01:46 by smabuza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include "../library/libft.h"

typedef	struct	s_list
{
	int			wdt;
	int			hgt;
	int			x;
	int			y;
	int			hy;
	int			hx;
}				t_list;

void			get_player_num(int *p1, int *p2);
void			read_input(int *x, int *y);
char			**data_map(int x, int y);
char			**data_piece(int x, int y);
int				check_piece(int change_dir, char **piece,
				t_list mvar, t_list pvar);
int				valid_move(char **map, char **piece,
		t_list mvar, t_list pvar);
int				output(int x, int y, int checker);
int				check_move(char **map, char **piece,
		t_list mvar, t_list pvar);
void			free_map(char **map, int j);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabuza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:42:03 by smabuza           #+#    #+#             */
/*   Updated: 2018/08/24 08:01:18 by smabuza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	free_map(char **map, int j)
{
	int i;

	i = 0;
	if (!map || !(*map))
		return ;
	if (*map)
	{
		while (i < j)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map[i]);
	}
	free(map);
	*map = NULL;
}

char	**data_map(int x, int y)
{
	char	**map;
	char	*line;
	char	**temp;
	int		i;

	i = 0;
	map = (char**)malloc((sizeof(char*) * (x + 1)));
	get_next_line(0, &line);
	free(line);
	while (i < x)
	{
		get_next_line(0, &line);
		map[i] = (char*)malloc((sizeof(char) * (y + 1)));
		temp = ft_strsplit((const char *)line, ' ');
		ft_strncpy(map[i], temp[1], y + 1);
		i++;
		free(line);
		free_map(temp, 2);
	}
	return (map);
}

void	get_player_num(int *p1, int *p2)
{
	char	*line;
	char	**temp;
	char	c;

	c = 'O';
	get_next_line(0, &line);
	temp = ft_strsplit((const char *)line, ' ');
	c = (temp[2][1] == '1') ? 'o' : 'x';
	free(line);
	free_map(temp, 3);
	if (c == 'o')
	{
		*p1 = 111;
		*p2 = 120;
	}
	if (c == 'x')
	{
		*p1 = 120;
		*p2 = 111;
	}
}

void	read_input(int *x, int *y)
{
	char	*line;
	char	**temp;

	get_next_line(0, &line);
	temp = ft_strsplit((const char *)line, ' ');
	*x = ft_atoi(temp[1]);
	*y = ft_atoi(temp[2]);
	free(line);
	free_map(temp, 3);
}

char	**data_piece(int x, int y)
{
	char	**piece;
	char	*line;
	int		i;

	i = 0;
	piece = (char**)malloc((sizeof(char*) * (x + 1)));
	while (i < x)
	{
		get_next_line(0, &line);
		piece[i] = (char*)malloc((sizeof(char) * (y + 1)));
		ft_strcpy(piece[i], line);
		i++;
		ft_strdel(&line);
	}
	return (piece);
}

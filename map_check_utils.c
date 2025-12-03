/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:48 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:05:36 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x, t_data *data)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		data->collec_f++;
	else if (map[y][x] == 'E')
		data->exit_f = 1;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, data);
	flood_fill(map, y - 1, x, data);
	flood_fill(map, y, x + 1, data);
	flood_fill(map, y, x - 1, data);
}

void	check_tile(char tile, t_data *data, int x, int y)
{
	if (tile == 'E')
	{
		data->exit++;
		data->exit_loc.x = x;
		data->exit_loc.y = y;
	}
	else if (tile == 'P')
	{
		data->start++;
		data->player_loc.x = x;
		data->player_loc.y = y;
	}
	else if (tile == 'C')
		data->collec++;
	else if (tile == '1')
		return ;
	else if (tile == '0')
		return ;
	else
		data->wrong_tile = 1;
	return ;
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (is_map(str[i]))
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_column(char **map, int row, t_data *data)
{
	int	i;
	int	height;

	i = 0;
	height = data->map_height;
	while (map[i] != NULL && i < height && is_map(map[i][row]))
	{
		if (map[i][row] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	size_check(char **map, t_data *data)
{
	int		win_x;
	int		win_y;

	data->map_width = get_width(map);
	win_x = data->map_width * TILE_DIM;
	win_y = data->map_height * TILE_DIM;
	if (win_x <= 1920 && win_y <= 1080)
		return (1);
	else
		return (0);
}

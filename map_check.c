/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:57 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:05:11 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char **map, t_data *data, int lines)
{
	char	**map_cpy;

	map_cpy = map_dup(map, lines);
	if (!map || !map[0])
		return (ft_error("Empty Map.\n", map_cpy));
	if (!is_rectangle(map_cpy, data))
		return (ft_error("Map is not a rectangle.\n", map_cpy));
	if (!char_error(map_cpy, data))
		return (ft_error("Map has wrong or non-existent characters.\n",
				map_cpy));
	if (!have_border(map_cpy, data))
		return (ft_error("Map does not have border.\n", map_cpy));
	if (!map_accessibility(map_cpy, data))
		return (ft_error("Map : game unable to be finished.\n", map_cpy));
	if (!size_check(map, data))
		return (ft_error("Map too big.\n", map_cpy));
	free_map(&map_cpy);
	return (1);
}

int	is_rectangle(char **map, t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	data->map_height = get_height(map);
	i = 0;
	while (i < data->map_height)
	{
		if (!map[i] || len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	char_error(char **map, t_data *data)
{
	int	i;
	int	j;

	data->collec = 0;
	data->start = 0;
	data->exit = 0;
	data->wrong_tile = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			check_tile(map[i][j], data, i, j);
			j++;
		}
		i++;
	}
	if (data->exit == 1 && data->start == 1 && data->collec > 0
		&& data->wrong_tile == 0)
		return (1);
	else
		return (0);
}

int	have_border(char **map, t_data *data)
{
	int	last;

	last = data->map_height;
	if (!check_line(map[0]) || !check_line(map[last - 1]))
		return (0);
	last = ft_strlen(map[0]);
	if (!check_column(map, 0, data) || !check_column(map, last - 1, data))
		return (0);
	return (1);
}

int	map_accessibility(char **map, t_data *data)
{
	data->collec_f = 0;
	data->exit_f = 0;
	flood_fill(map, data->player_loc.x, data->player_loc.y, data);
	if (data->collec_f == data->collec && data->exit_f == 1)
		return (1);
	else
		return (0);
}

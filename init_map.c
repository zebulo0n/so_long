/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:19 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/25 12:06:02 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *file, t_data *data)
{
	int		i;
	int		fd;
	int		lines;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0 || count_lines(file) == -1)
		return (NULL);
	lines = count_lines(file);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (!map_check(map, data, lines))
		return (exit_init(map));
	close(fd);
	return (map);
}

int	init_display(char *file, t_mlx *vars)
{
	vars->catched = 0;
	vars->moves = 0;
	vars->map = get_map(file, &vars->data);
	if (!vars->map)
		return (0);
	vars->win_x = get_width(vars->map) * TILE_DIM;
	vars->win_y = get_height(vars->map) * TILE_DIM;
	vars->link = mlx_init();
	vars->win = mlx_new_window(vars->link, vars->win_x, vars->win_y, "so_long");
	init_tiles(vars);
	if (!vars->water || !vars->full || !vars->player || !vars->collec
		|| !vars->exit)
		return (0);
	display_map(vars->map, *vars);
	return (1);
}

int	format_check(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b' && str[i
			- 4] == '.')
		return (1);
	else
		return (0);
}

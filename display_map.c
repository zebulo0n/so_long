/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:00:08 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:07:23 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tiles(t_mlx *vars)
{
	int	h;

	vars->water = mlx_xpm_file_to_image(vars->link, "assets/water.xpm", &h, &h);
	vars->full = mlx_xpm_file_to_image(vars->link, "assets/full.xpm", &h, &h);
	vars->player = mlx_xpm_file_to_image(vars->link, "assets/red_hood.xpm", &h,
			&h);
	vars->collec = mlx_xpm_file_to_image(vars->link, "assets/potion.xpm", &h,
			&h);
	vars->exit = mlx_xpm_file_to_image(vars->link, "assets/portal.xpm", &h, &h);
}

void	place_tile(char c, t_mlx *gen, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(gen->link, gen->win, gen->water, j * TILE_DIM, i
			* TILE_DIM);
	else if (c == '0')
		mlx_put_image_to_window(gen->link, gen->win, gen->full, j * TILE_DIM, i
			* TILE_DIM);
	else if (c == 'E')
		mlx_put_image_to_window(gen->link, gen->win, gen->exit, j * TILE_DIM, i
			* TILE_DIM);
	else if (c == 'C')
		mlx_put_image_to_window(gen->link, gen->win, gen->collec, j * TILE_DIM,
			i * TILE_DIM);
	else if (c == 'P')
		mlx_put_image_to_window(gen->link, gen->win, gen->player, j * TILE_DIM,
			i * TILE_DIM);
	return ;
}

void	display_moves(t_mlx *vars)
{
	char	*str_moves;
	char	*nbr;

	nbr = ft_itoa(vars->moves);
	str_moves = ft_strjoin("Move Count : ", nbr);
	free(nbr);
	mlx_string_put(vars->link, vars->win, 10, 15, 0xFFFFFFFF, str_moves);
	free(str_moves);
}

void	display_map(char **map, t_mlx vars)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			place_tile(map[i][j], &vars, i, j);
			j++;
		}
		i++;
	}
	display_moves(&vars);
}

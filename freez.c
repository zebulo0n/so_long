/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freez.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:01 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:07:46 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tiles(t_mlx *vars)
{
	if (!vars || !vars->link)
		return ;
	if (vars->water)
	{
		mlx_destroy_image(vars->link, vars->water);
		vars->water = NULL;
	}
	if (vars->full)
	{
		mlx_destroy_image(vars->link, vars->full);
		vars->full = NULL;
	}
}

void	free_sprites(t_mlx *vars)
{
	if (!vars || !vars->link)
		return ;
	if (vars->player)
	{
		mlx_destroy_image(vars->link, vars->player);
		vars->player = NULL;
	}
	if (vars->collec)
	{
		mlx_destroy_image(vars->link, vars->collec);
		vars->collec = NULL;
	}
	if (vars->exit)
	{
		mlx_destroy_image(vars->link, vars->exit);
		vars->exit = NULL;
	}
}

char	**exit_init(char **map)
{
	free_map(&map);
	return (NULL);
}

void	free_game(t_mlx *vars)
{
	if (!vars)
		return ;
	if (vars->map)
	{
		free_map(&vars->map);
		vars->map = NULL;
	}
	if (vars->win && vars->link)
	{
		mlx_destroy_window(vars->link, vars->win);
		vars->win = NULL;
	}
	if (vars->link)
	{
		mlx_destroy_display(vars->link);
		free(vars->link);
		vars->link = NULL;
	}
}

int	exit_game(t_mlx *vars)
{
	free_tiles(vars);
	free_sprites(vars);
	free_game(vars);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:14 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/25 12:10:20 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_position(int new_x, int new_y, t_mlx *vars)
{
	if (new_x >= 0 && new_x < vars->data.map_height && new_y >= 0
		&& new_y < vars->data.map_width && vars->map[new_x][new_y] != '1'
		&& vars->map[new_x][new_y] != 'E')
	{
		if (vars->map[new_x][new_y] == 'C')
			vars->catched++;
		return (1);
	}
	else
		return (0);
}

void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 'w' || keycode == 65362)
		(*new_x)--;
	else if (keycode == 's' || keycode == 65364)
		(*new_x)++;
	else if (keycode == 'a' || keycode == 65361)
		(*new_y)--;
	else if (keycode == 'd' || keycode == 65363)
		(*new_y)++;
}

void	move_player(t_mlx *vars, int new_x, int new_y)
{
	if (vars->map[vars->data.player_loc.x][vars->data.player_loc.y] != 'E')
		vars->map[vars->data.player_loc.x][vars->data.player_loc.y] = '0';
	vars->map[new_x][new_y] = 'P';
	vars->data.player_loc.x = new_x;
	vars->data.player_loc.y = new_y;
	vars->moves++;
}

int	player_move(int keycode, t_mlx *vars)
{
	int	new_x;
	int	new_y;

	if (keycode == 65307)
		return (exit_game(vars));
	new_x = vars->data.player_loc.x;
	new_y = vars->data.player_loc.y;
	update_position(keycode, &new_x, &new_y);
	if ((new_x != vars->data.player_loc.x || new_y != vars->data.player_loc.y)
		&& validate_position(new_x, new_y, vars))
		move_player(vars, new_x, new_y);
	if (vars->map[new_x][new_y] == 'E' && vars->catched == vars->data.collec)
	{
		write(1, "It's-a-win\n", 11);
		return (exit_game(vars));
	}
	display_map(vars->map, *vars);
	return (1);
}

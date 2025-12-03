/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:32 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:05:50 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	vars;

	if (ac != 2)
		return (0);
	if (!format_check(av[1]))
		return (ft_errorr("Error : file's format type must be .ber\n"));
	if (!init_display(av[1], &vars))
		return (0);
	mlx_hook(vars.win, 2, 1L << 0, player_move, &vars);
	mlx_hook(vars.win, 17, 0, exit_game, &vars);
	mlx_loop(vars.link);
}

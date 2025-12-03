/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:00:11 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:08:18 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str, char **map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	free_map(&map);
	return (0);
}

int	ft_errorr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (0);
}

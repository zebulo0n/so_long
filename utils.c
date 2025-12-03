/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:02:31 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:04:15 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	count = 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		x;
	int		size;

	size = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	x = 0;
	while (x < size && src[x] != '\n' && src[x] != '\0')
	{
		cpy[x] = src[x];
		x++;
	}
	cpy[x] = '\0';
	return (cpy);
}

int	is_map(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	else
		return (0);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
		i++;
	return (i);
}

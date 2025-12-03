/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:02:19 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:02:21 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_DIM 32

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_data
{
	int		exit;
	t_point	exit_loc;
	int		start;
	t_point	player_loc;
	int		collec;
	int		wrong_tile;
	int		exit_f;
	int		collec_f;
	int		map_height;
	int		map_width;
}			t_data;

// typedef struct s_tiles
// {
//     void *full;
// 	void *water;

//     void *player;
//     void *collec;
//     void *exit;
// } t_tiles;

typedef struct s_mlx
{
	char	**map;
	t_data	data;

	void	*full;
	void	*water;
	void	*player;
	void	*collec;
	void	*exit;

	void	*link;
	void	*win;
	int		win_x;
	int		win_y;

	int		catched;
	int		moves;

}			t_mlx;

/// MAP CREATION
int			count_lines(char *file);
void		init_tiles(t_mlx *vars);
void		display_map(char **map, t_mlx vars);
char		**get_map(char *file, t_data *data);
int			init_display(char *file, t_mlx *vars);

/// MAP CHECK
int			map_check(char **map, t_data *data, int lines);
int			is_rectangle(char **map, t_data *data);
int			char_error(char **map, t_data *data);
int			have_border(char **map, t_data *data);
int			map_accessibility(char **map, t_data *data);
int			size_check(char **map, t_data *data);
int			format_check(char *str);

void		flood_fill(char **map, int y, int x, t_data *data);
void		check_tile(char tile, t_data *data, int x, int y);
int			check_line(char *str);
int			check_column(char **map, int row, t_data *data);
char		**map_dup(char **map, int lines);

int			player_move(int keycode, t_mlx *vars);

/// FREES
void		free_map(char ***arr);
int			exit_game(t_mlx *vars);
char		**exit_init(char **map);

/// UTILS
char		*ft_strdup(char *src);
int			is_map(char c);
int			get_height(char **map);
int			get_width(char **map);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
int			sp_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
void		*ft_memset(void *s, int c, int n);

int			ft_error(char *str, char **map);
int			ft_errorr(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:55:20 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/25 11:55:57 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf
{
	char			*buf;
	struct s_buf	*next;
}					t_buf;

char				*get_next_line(int fd);
void				content_to_node(int fd, t_buf **stash);
void				buf_to_node(t_buf **stash, char *buf, int nbytes_read);
void				node_to_line(t_buf *stash, char **line);
void				clean_output(t_buf **stash);
int					is_newline(t_buf *stash);
t_buf				*ft_lstlast(t_buf *lst);
void				malloc_line_size(char **line, t_buf *stash);
void				free_stash(t_buf *stash);
int					ft_strlen(const char *str);

#endif
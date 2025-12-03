/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:55:16 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/02 16:58:27 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	content_to_node(fd, &stash);
	if (!stash)
		return (NULL);
	node_to_line(stash, &line);
	clean_output(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	content_to_node(int fd, t_buf **stash)
{
	char	*buf;
	int		nbytes_read;

	nbytes_read = 1;
	while (!is_newline(*stash) && nbytes_read > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		nbytes_read = (int)read(fd, buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(buf);
			return ;
		}
		buf[nbytes_read] = '\0';
		buf_to_node(stash, buf, nbytes_read);
		free(buf);
	}
}

void	buf_to_node(t_buf **stash, char *buf, int nbytes_read)
{
	int		i;
	t_buf	*last_buf;
	t_buf	*new_node;

	new_node = malloc(sizeof(t_buf));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->buf = malloc(sizeof(char) * (nbytes_read + 1));
	if (!new_node->buf)
		return ;
	i = 0;
	while (buf[i] && i < nbytes_read)
	{
		new_node->buf[i] = buf[i];
		i++;
	}
	new_node->buf[i] = '\0';
	if (!*stash)
	{
		*stash = new_node;
		return ;
	}
	last_buf = ft_lstlast(*stash);
	last_buf->next = new_node;
}

void	node_to_line(t_buf *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	malloc_line_size(line, stash);
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->buf[j])
		{
			if (stash->buf[j] == '\n')
			{
				(*line)[i++] = stash->buf[j];
				break ;
			}
			(*line)[i++] = stash->buf[j++];
		}
		stash = stash->next;
	}
	(*line)[i] = '\0';
}

void	clean_output(t_buf **stash)
{
	t_buf	*last_buf;
	t_buf	*static_node;
	int		displayed;
	int		i;

	static_node = malloc(sizeof(t_buf));
	if (!stash || !static_node)
		return ;
	static_node->next = NULL;
	last_buf = ft_lstlast(*stash);
	displayed = 0;
	while (last_buf->buf[displayed] && last_buf->buf[displayed] != '\n')
		displayed++;
	if (last_buf->buf && last_buf->buf[displayed] == '\n')
		displayed++;
	static_node->buf = malloc(sizeof(char) * ((ft_strlen(last_buf->buf)
					- displayed) + 1));
	if (!static_node->buf)
		return ;
	i = 0;
	while (last_buf->buf[displayed])
		static_node->buf[i++] = last_buf->buf[displayed++];
	static_node->buf[i] = '\0';
	free_stash(*stash);
	*stash = static_node;
}

// int main()
// {
//     int fd = 42;
//     char *line = "1";

//     //fd = open("test.txt", O_RDONLY);
//     while (line != NULL)
//     {
//         line = get_next_line(fd);
//         printf("%s\n", line);
//         free(line);
//     }
// }

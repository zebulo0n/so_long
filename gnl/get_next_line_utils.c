/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:57:57 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/25 11:56:12 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(t_buf *stash)
{
	int		i;
	t_buf	*current;

	if (!stash)
		return (0);
	current = ft_lstlast(stash);
	i = 0;
	while (current->buf[i])
	{
		if (current->buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_buf	*ft_lstlast(t_buf *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->next)
		lst = lst->next;
	return (lst);
}

void	malloc_line_size(char **line, t_buf *stash)
{
	int	i;
	int	size;

	size = 0;
	while (stash)
	{
		i = 0;
		while (stash->buf[i])
		{
			if (stash->buf[i] == '\n')
			{
				size++;
				break ;
			}
			size++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (size + 1));
	if (*line == NULL)
		return ;
}

void	free_stash(t_buf *stash)
{
	t_buf	*current;
	t_buf	*tmp;

	current = stash;
	while (current)
	{
		free(current->buf);
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	ft_strlen(const char *str)
{
	int	cmptr;

	cmptr = 0;
	while (str[cmptr])
		cmptr++;
	return (cmptr);
}

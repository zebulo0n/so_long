/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:02:55 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:03:50 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

int	sp_map(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	else
		return (0);
}

int	sp_strlen(char *str)
{
	int	cmptr;

	cmptr = 0;
	while (sp_map(str[cmptr]))
		cmptr++;
	return (cmptr);
}

void	*ft_memset(void *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

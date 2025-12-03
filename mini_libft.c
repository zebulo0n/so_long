/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:02:04 by zoeschne          #+#    #+#             */
/*   Updated: 2025/08/11 15:04:53 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_numlen(long int nb)
{
	int	cmptr;

	cmptr = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		cmptr++;
	}
	return (cmptr);
}

char	*fill_nb(char *array, long int nb, int size, int sign)
{
	int	i;

	array[size] = '\0';
	if (nb == 0)
	{
		array[0] = '0';
		return (array);
	}
	i = size - 1;
	while (nb > 0)
	{
		array[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == 1)
		array[0] = '-';
	return (array);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		sign;
	int		size;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign++;
		nb = -nb;
	}
	size = ft_numlen(nb) + sign;
	array = malloc(sizeof(char) * (size + 1));
	if (!array)
		return (NULL);
	return (fill_nb(array, nb, size, sign));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total_size;
	int		i;
	int		j;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * total_size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	**map_dup(char **map, int lines)
{
	char	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * lines + 1);
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

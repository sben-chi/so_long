/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:51:21 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/19 11:53:55 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str, int len)
{
	write(2, "Error : ", 9);
	write(2, str, len);
	exit(0);
	return (1);
}

void	check_extention(char *s1)
{
	int		i;
	int		j;
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	i = len - 1;
	j = 3;
	s2 = ".ber";
	while (i > len - 5)
	{
		if (s1[i--] != s2[j--] || i < 0)
			ft_error("bad file\n", 9);
	}
	return ;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

t_map	*new(char *line)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

int	add_back(t_map **map, t_map **last, t_map *nnode)
{
	if (!nnode)
		return (1);
	if (!(*map))
	{
		(*map) = nnode;
		(*last) = (*map);
	}
	(*last)->next = nnode;
	(*last) = (*last)->next;
	return (1);
}

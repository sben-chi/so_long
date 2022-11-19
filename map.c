/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:52:04 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/19 11:25:31 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**from_list_to_table(t_data *list)
{
	char	**t;
	t_map	*l;
	int		i;

	i = 0;
	l = list->lmap;
	t = malloc(sizeof(char *) * list->length);
	while (l)
	{
		t[i++] = l->line;
		l = l->next;
	}
	return (t);
}

int	check_walls(t_data *dataMap, t_map *last)
{
	int		i;
	t_map	*t;

	i = -1;
	t = dataMap->lmap;
	last->line[dataMap->width - 1] != '\0'
		&& ft_error("your map doesn't surrounded by walls\n", 37);
	while (++i < dataMap->width - 1)
		(t->line[i] != '1' || last->line[i] != '1')
		&& ft_error("your map doesn't surrounded by walls\n", 37);
	i = 0;
	while (i++ < dataMap->length - 2)
	{
		t = t->next;
		(t->line[0] != '1' || t->line[dataMap->width - 2] != '1')
		&& ft_error("your map doesn't surrounded by walls\n", 37);
	}
	return (1);
}

int	check_components(t_data *vr)
{
	int		i;
	int		b;
	t_map	*t;

	t = vr->lmap;
	while (t->next)
	{
		t = t->next;
		i = 0;
		while (i++ < vr->width - 2)
		{
			b = (t->line[i] != '0' && t->line[i] != '1' && t->line[i] != 'E'
					&& t->line[i] != 'C' && t->line[i] != 'P');
			vr->c += (t->line[i] == 'C');
			vr->e += (t->line[i] == 'E');
			vr->p += (t->line[i] == 'P');
			vr->enm += (t->line[i] == 'M');
			((!vr->bonus && b) || (b && t->line[i] != 'M')
				|| vr->p > 1) && ft_error("problem in components/player\n", 29);
		}
	}
	(!vr->c || !vr->p || !vr->e)
	&& ft_error("lack of an element(s)\n", 22);
	return (1);
}

void	read_map(t_data *data_map, char *map)
{
	int			fd;
	char		*l;
	t_map		*last;
	static char	b;

	fd = open(map, O_RDONLY);
	fd < 0 && ft_error("in your file\n", 13);
	l = get_next_line(fd);
	data_map->width = ft_strlen(l);
	data_map->length = 0;
	data_map->lmap = NULL;
	last = NULL;
	while (l)
	{	
		if (!b && data_map->width - 1 == ft_strlen(l))
			b = '1';
		else if (b == '1' || data_map->width != ft_strlen(l))
			ft_error("map must be rectangular\n", 24);
		data_map->length += add_back(&data_map->lmap, &last, new(l));
		l = get_next_line(fd);
	}
	if (data_map->width != ft_strlen(last->line) + 1)
		ft_error("map must be rectangular\n", 24);
	(check_walls(data_map, last)) && (check_components(data_map)) && close(fd);
	data_map->t = from_list_to_table(data_map);
}

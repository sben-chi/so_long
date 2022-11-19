/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:15:38 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/19 11:55:18 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 7

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct map
{
	char		*line;
	struct map	*next;
}t_map;

typedef struct data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**t;
	char	*enemy[7];
	int		moves;
	char	*addr;
	char	*col;
	char	*wall;
	char	*exit;
	char	*player;
	char	*emp_sp;
	char	*m;
	int		line;
	int		endian;
	int		length;
	int		width;
	int		e;
	int		p;
	int		c;
	int		enm;
	int		x_player;
	int		y_player;
	int		bonus;
	t_map	*lmap;
}t_data;

char	*get_next_line(int fd);
int		ft_error(char *str, int len);
void	check_extention(char *s1);
void	read_map(t_data *data_map, char *map);
t_map	*new(char *line);
int		add_back(t_map **map, t_map **last, t_map *nnode);
int		ft_strlen(char *s);
void	draw_map(t_data *vars, char c);
int		movements(int key, t_data *data);
char	*ft_itoa(int n);
int		end_game(char c);
int		my_exit(void);
int		set_enemies_data(t_data *vr);

#endif

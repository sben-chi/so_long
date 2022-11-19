/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:32:58 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/19 10:50:15 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_enemies_data(t_data *vr)
{
	vr->enemy[0] = "xpm_imgs/M1.xpm";
	vr->enemy[1] = "xpm_imgs/M2.xpm";
	vr->enemy[2] = "xpm_imgs/M3.xpm";
	vr->enemy[3] = "xpm_imgs/M4.xpm";
	vr->enemy[4] = "xpm_imgs/M5.xpm";
	vr->enemy[5] = "xpm_imgs/M6.xpm";
	vr->enemy[6] = "xpm_imgs/M7.xpm";
	return (1);
}

int	myput_img(t_data *vars, char *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img, x, y);
	return (1);
}

void	draw(t_data *vr)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < vr->length)
	{
		j = -1;
		k = vr->bonus + i;
		while (++j < vr->width - 1)
		{
			vr->t[i][j] == '1' && myput_img(vr, vr->wall, j * 32, k * 32);
			vr->t[i][j] != '1' && myput_img(vr, vr->emp_sp, j * 32, k * 32);
			vr->t[i][j] == 'C' && myput_img(vr, vr->col, j * 32, k * 32);
			vr->t[i][j] == 'E' && myput_img(vr, vr->exit, j * 32, k * 32);
			vr->t[i][j] == 'M' && myput_img(vr, vr->m, j * 32, k * 32);
			if (vr->t[i][j] == 'P')
			{	
				myput_img(vr, vr->player, j * 32, k * 32);
				vr->x_player = j;
				vr->y_player = i;
			}
		}
	}
}

void	draw_map(t_data *vr, char c)
{
	int	i;

	i = 32;
	vr->wall = mlx_xpm_file_to_image
		(vr->mlx_ptr, "xpm_imgs/wall.xpm", &i, &i);
	vr->emp_sp = mlx_xpm_file_to_image
		(vr->mlx_ptr, "xpm_imgs/06.xpm", &i, &i);
	vr->col = mlx_xpm_file_to_image
		(vr->mlx_ptr, "xpm_imgs/C3.xpm", &i, &i);
	if (c == 'r')
		vr->player = mlx_xpm_file_to_image
			(vr->mlx_ptr, "xpm_imgs/Pr.xpm", &i, &i);
	if (c == 'l')
		vr->player = mlx_xpm_file_to_image
			(vr->mlx_ptr, "xpm_imgs/Pl.xpm", &i, &i);
	vr->exit = mlx_xpm_file_to_image
		(vr->mlx_ptr, "xpm_imgs/exit0.xpm", &i, &i);
	(!vr->wall || !vr->emp_sp || !vr->col || !vr->player || !vr->exit)
		&& ft_error("there is a problem in your xmp file(s).\n", 40);
	draw(vr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:33:24 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/19 12:03:31 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("invalid input!!!!\n", 18);
	data.moves = 0;
	data.c = 0;
	data.p = 0;
	data.e = 0;
	data.enm = 0;
	data.bonus = 0;
	check_extention(av[1]);
	read_map(&data, av[1]);
	data.mlx_ptr = mlx_init();
	!data.mlx_ptr && ft_error("in mlx_ptr!!!\n", 14);
	data.win_ptr = mlx_new_window
		(data.mlx_ptr, (data.width - 1) * 32, data.length * 32, "so_long");
	!data.win_ptr && ft_error("in win_ptr!!!\n", 14);
	draw_map(&data, 'r');
	mlx_key_hook(data.win_ptr, movements, &data);
	mlx_hook(data.win_ptr, 17, 0, my_exit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

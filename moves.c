/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:57:55 by sben-chi          #+#    #+#             */
/*   Updated: 2022/05/23 11:23:25 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(char c)
{
	if (c == 'w')
		write(1, "Congratulations ^_^\n", 20);
	else if (c == 'l')
		write(1, "Sorry :(\n", 9);
	else
		exit(write(1, "We just started having fun :(\n", 30));
	return (1);
}

int	my_exit(void)
{
	return (end_game('n'));
}

void	display_moves(t_data *vr)
{
	char	*msg;

	msg = ft_itoa(++vr->moves);
	if (vr->bonus)
	{
		mlx_string_put(vr->mlx_ptr, vr->win_ptr, 5, 5, 0xE8E8E8, "moves: ");
		mlx_string_put(vr->mlx_ptr, vr->win_ptr, 2.2 * 32, 5, 0xE8E8E8, msg);
	}
	write(1, "moves: ", 7);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	free(msg);
}

int	fct_move(t_data *vr, int x, int y, char a)
{
	if (vr->t[y][x] == '1' || (vr->t[y][x] == 'E' && vr->c))
		return (0);
	mlx_clear_window(vr->mlx_ptr, vr->win_ptr);
	if (vr->bonus && vr->t[y][x] == 'M')
		exit(end_game('l'));
	else if (vr->t[y][x] == 'E' && !vr->c)
	{
		vr->t[vr->y_player][vr->x_player] = '0';
		draw_map(vr, a);
	}
	else if (vr->t[y][x] == '0' || vr->t[y][x] == 'C')
	{
		if (vr->t[y][x] == 'C')
			vr->c--;
		vr->t[vr->y_player][vr->x_player] = '0';
		vr->t[y][x] = 'P';
		draw_map(vr, a);
	}
	display_moves(vr);
	return (1);
}

int	movements(int key, t_data *vr)
{
	key == 53 && end_game('n');
	if (!vr->c && vr->t[vr->y_player][vr->x_player] == '0')
		exit(end_game('w'));
	key == 13 && fct_move(vr, vr->x_player, vr->y_player - 1, 'n');
	key == 1 && fct_move(vr, vr->x_player, vr->y_player + 1, 'n');
	key == 2 && fct_move(vr, vr->x_player + 1, vr->y_player, 'r');
	key == 0 && fct_move(vr, vr->x_player - 1, vr->y_player, 'l');
	return (1);
}

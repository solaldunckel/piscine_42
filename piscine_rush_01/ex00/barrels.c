/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barrels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:20:52 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/16 19:25:45 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_empty_board(int board[5][5])
{
	int		y;
	int		x;

	y = 1;
	while (y <= 4)
	{
		x = 1;
		while (x <= 4)
		{
			board[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	print_board(int board[5][5])
{
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			ft_putnbr(board[i][j]);
			if (j < 4)
				ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int		check(int k, int board[5][5], int y, int x)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		if (board[i][x] == k)
			return (0);
		i++;
	}
	i = 1;
	while (i <= 4)
	{
		if (board[y][i] == k)
			return (0);
		i++;
	}
	return (1);
}

int		recursive_towers(int board[5][5], int y, int x, int **pov)
{
	int		val;

	val = 1;
	while (val <= 4)
	{
		if (check(val, board, y, x))
		{
			board[y][x] = val;
			val = 5;
		}
		val++;
	}
	if (y <= 4 && x <= 4)
	{
		if (y <= 4)
			recursive_towers(board, y, x + 1, pov);
		if (x <= 4)
			recursive_towers(board, y + 1, x, pov);
	}
	if (x == 4)
		return (0);
	return (0);
}

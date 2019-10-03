/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:38:34 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/16 19:25:03 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		check_pov(char *str);
int		**get_pov(char *str);
void	fill_empty_board(int board[5][5]);
void	print_board(int board[5][5]);
int		check_line_column(int k, int board[5][5], int y, int x);
int		recursive_towers(int board[5][5], int y, int x, int **pov);

#endif

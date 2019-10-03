/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcharpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:25:56 by trcharpi          #+#    #+#             */
/*   Updated: 2019/06/08 13:26:08 by trcharpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char c, char d, char e)
{
	int		i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(c);
		else if (i == x)
			ft_putchar(e);
		else
			ft_putchar(d);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (i == 1)
	{
		print_line(x, 'A', 'B', 'C');
		i++;
	}
	while (i > 1 && i < y)
	{
		print_line(x, 'B', ' ', 'B');
		i++;
	}
	while (i == y)
	{
		print_line(x, 'C', 'B', 'A');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcharpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:25:56 by trcharpi          #+#    #+#             */
/*   Updated: 2019/06/08 12:28:18 by trcharpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char c, char d)
{
	int		i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar(c);
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
		print_line(x, 'A', 'B');
		i++;
	}
	while (i > 1 && i < y)
	{
		print_line(x, 'B', ' ');
		i++;
	}
	while (i == y)
	{
		print_line(x, 'C', 'B');
		i++;
	}
}

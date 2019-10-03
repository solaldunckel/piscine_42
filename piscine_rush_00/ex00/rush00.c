/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:35:25 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/09 16:18:04 by sdunckel         ###   ########.fr       */
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
		print_line(x, 'o', '-');
		i++;
	}
	while (i > 1 && i < y)
	{
		print_line(x, '|', ' ');
		i++;
	}
	while (i == y)
	{
		print_line(x, 'o', '-');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:08:05 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/24 13:49:09 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_arg(char *str)
{
	if (str[0] == '-' || str[0] == '+' || str[0] == '/' || str[0] == '*'
	|| str[0] == '%')
		return (1);
	return (0);
}

void	operation(int nb1, int nb2, char operator)
{
	if (operator == '-')
		ft_putnbr(sub(nb1, nb2));
	else if (operator == '+')
		ft_putnbr(add(nb1, nb2));
	else if (operator == '/')
	{
		if (nb2 == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(divide(nb1, nb2));
		return ;
	}
	else if (operator == '*')
		ft_putnbr(multiply(nb1, nb2));
	else if (operator == '%')
	{
		if (nb2 == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(modulo(nb1, nb2));
		return ;
	}
}

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	char	operator;

	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (0);
	}
	if (!check_arg(argv[2]))
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (0);
	}
	operator = argv[2][0];
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	operation(nb1, nb2, operator);
	ft_putstr("\n");
}

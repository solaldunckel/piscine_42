/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:20:08 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/13 18:01:45 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_base(char *base)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 127)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_base(long int num, char *base)
{
	long int	len;

	len = ft_strlen(base);
	if (num >= len)
		convert_base(num / len, base);
	ft_putchar(base[num % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbr2;

	nbr2 = nbr;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr2 = -nbr2;
		}
		convert_base(nbr2, base);
	}
}

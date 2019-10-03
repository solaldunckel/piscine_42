/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:13:02 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/20 20:54:50 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int std)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

void	ft_print_name(char *str)
{
	ft_putstr("==> ", 1);
	ft_putstr(str, 1);
	ft_putstr(" <==", 1);
	ft_putstr("\n", 1);
}

int		ft_atoi(char *str)
{
	int		atoi;
	int		i;

	atoi = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi);
}

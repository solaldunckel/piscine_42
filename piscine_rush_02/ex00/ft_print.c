/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroppel <aroppel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:14:52 by aroppel           #+#    #+#             */
/*   Updated: 2019/06/23 18:58:19 by aroppel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_more(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int		ft_put_cen(char *str, char **tab, int i, int len)
{
	ft_putstr(tab[str[i] - '0']);
	write(1, " ", 1);
	ft_putstr(tab[28]);
	if ((str[i + 1] == '0' && str[i + 2] == '0') && (len > 3))
	{
		write(1, " ", 1);
		ft_putstr(tab[27 + (len / 3)]);
		return (0);
	}
	if (ft_more(str, i + 1))
		return (0);
	return (1);
}

int		ft_put_diz(char *str, char **tab, int i, int len)
{
	if (str[i] == '1' && str[i + 1] != '0')
	{
		ft_putstr(tab[(str[i + 1] - '0' + 9)]);
		if (len > 3)
		{
			write(1, " ", 1);
			ft_putstr(tab[28 + (len / 3)]);
			if (ft_more(str, i + 2))
				write(1, " ", 1);
		}
		return (1);
	}
	else
		ft_putstr(tab[(str[i] - '0') + 18]);
	if ((str[i + 1] == '0') && (len > 3))
	{
		write(1, " ", 1);
		ft_putstr(tab[28 + (len / 3)]);
	}
	if (ft_more(str, i + 1))
		return (0);
	return (1);
}

int		ft_put_uni(char *str, char **tab, int i, int len)
{
	if (i == 0 && len == 1)
	{
		ft_putstr(tab[str[i] - '0']);
		return (1);
	}
	if (len > 3 && str[i - 1] != '1')
	{
		ft_putstr(tab[str[i] - '0']);
		write(1, " ", 1);
		ft_putstr(tab[28 + (len / 3)]);
		if (ft_more(str, i + 1))
			return (0);
		return (1);
	}
	else if (str[i - 1] != '1')
		ft_putstr(tab[str[i] - '0']);
	if (ft_more(str, i + 1) && str[i - 1] != '1')
		return (0);
	return (1);
}

void	ft_print(char *str, char **tab)
{
	int		i;
	int		len;
	int		can;

	len = ft_strlen(str);
	i = 0;
	if (zero_check(str))
		ft_putstr(tab[str[i] - '0']);
	while (len > 0)
	{
		if (str[i] - '0' != 0)
		{
			if (len % 3 == 0)
				can = ft_put_cen(str, tab, i, len);
			else if (len % 3 == 2)
				can = ft_put_diz(str, tab, i, len);
			else
				can = ft_put_uni(str, tab, i, len);
			if (can != 1 && len > 1 && ft_more(str, i + 1))
				write(1, " ", 1);
		}
		i++;
		len--;
	}
	write(1, "\n", 1);
}

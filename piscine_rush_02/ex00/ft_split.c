/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroppel <aroppel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:05:30 by aroppel           #+#    #+#             */
/*   Updated: 2019/06/22 17:20:36 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_isspace(char *str)
{
	return (*str == '\n' || *str == '\f' || *str == '\r' || *str == '\v'
			|| *str == '\t' || *str == ' ');
}

char	*ft_split(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != ':')
		i++;
	i++;
	while (ft_isspace(&tab[i]) == 1)
		i++;
	while (tab[i] != '\0')
	{
		if (!(ft_isspace(&tab[i]) && ft_isspace(&tab[i + 1])))
		{
			tab[j] = tab[i];
			tab[i] = ' ';
			j++;
		}
		i++;
	}
	tab[j - 1] = '\0';
	return (tab);
}

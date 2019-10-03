/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_barrels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:49:07 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/16 17:51:42 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_pov(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str <= '4' && *str >= '1')
			i++;
		str++;
	}
	if (i != 16)
		return (0);
	return (1);
}

int		**get_pov(char *str)
{
	int		**pov;
	int		i;
	int		j;

	i = 1;
	j = 1;
	pov = malloc(sizeof(int) * 9);
	while (*str)
	{
		if (i == 1)
			pov[j] = malloc(sizeof(int) * 9);
		if (*str <= '4' && *str >= '1')
		{
			pov[j][i] = *str - 48;
			i++;
		}
		if (i == 5)
		{
			i = 1;
			j++;
		}
		str++;
	}
	return (pov);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:47:24 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/21 15:52:42 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*mod_tab;

	i = -1;
	if (!(mod_tab = malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (++i < length)
		mod_tab[i] = (*f)(tab[i]);
	return (mod_tab);
}

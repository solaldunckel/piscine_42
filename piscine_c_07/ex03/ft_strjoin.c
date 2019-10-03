/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:08:07 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/19 22:42:48 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*cat_n_join(int size, char **strs, char *sep, char *tab)
{
	int		i;
	int		j;
	int		k;

	j = -1;
	k = 0;
	while (++j < size)
	{
		i = -1;
		while (strs[j][++i])
			tab[k++] = strs[j][i];
		if (j < size - 1)
		{
			i = -1;
			while (sep[++i])
				tab[k++] = sep[i];
		}
	}
	tab[k] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		mem;
	int		j;

	mem = 0;
	j = 0;
	while (j < size)
	{
		mem = mem + ft_strlen(strs[j]) + ft_strlen(sep) + 1;
		j++;
	}
	if (!(tab = malloc(sizeof(char) * mem)))
		return (NULL);
	if (size == 0)
		return (tab);
	tab = cat_n_join(size, strs, sep, tab);
	return (tab);
}

int		main(int ac, char **av)
{
	printf(ft_strjoin(ac - 2, &av[2], ac[1]));
	return (0);
}

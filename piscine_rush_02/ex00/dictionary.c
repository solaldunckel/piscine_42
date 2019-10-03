/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:45:35 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/23 17:12:38 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (count_total(tab[i]) > count_total(tab[j]))
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int		count_lines(int fd)
{
	int		count;
	char	buf[2];
	int		ret;

	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			count++;
	}
	return (count);
}

void	malloc_tab(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		ret;

	i = 0;
	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		i++;
		if (buf[0] == '\n')
		{
			if (!(tab[count] = malloc(sizeof(char*) * (i + 1))))
				return ;
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

void	read_and_fill(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		ret;

	i = 0;
	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		tab[count][i] = buf[0];
		tab[count][i + 1] = '\0';
		i++;
		if (buf[0] == '\n')
		{
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

char	**parse_dictionary(void)
{
	char	**tab;
	int		fd;
	int		i;

	if ((fd = open(DICT_FILE, O_RDONLY)) == -1)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (count_lines(fd) + 1))))
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open(DICT_FILE, O_RDONLY)) == -1)
		return (tab);
	malloc_tab(tab, fd);
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open(DICT_FILE, O_RDONLY)) == -1)
		return (tab);
	read_and_fill(tab, fd);
	ft_sort_string_tab(tab);
	if (close(fd) == -1)
		return (NULL);
	i = -1;
	while (tab[++i])
		ft_split(tab[i]);
	return (tab);
}

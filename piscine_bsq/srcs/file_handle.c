/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 01:33:08 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 22:44:53 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		free_all(t_all *all)
{
	ft_strdel(&(all->line));
	ft_memdel((void **)&(all->prev));
	ft_memdel((void **)&(all->curr));
	free(all);
}

int			*select_prev(t_all *all)
{
	return (all->swap ? all->curr : all->prev);
}

int			*select_curr(t_all *all)
{
	return (all->swap ? all->prev : all->curr);
}

int			init_map(t_all *all, int fd)
{
	int		i;

	if (get_next_line(fd, &all->line) == FAILURE)
		return (set_error(all, ERROR_SYS));
	if (!all->line || !ft_strlen(all->line))
		return (set_error(all, ERROR_MAP));
	if ((all->nb_line = ft_atoi(all->line)) < 0)
		return (set_error(all, ERROR_MAP));
	i = -1;
	while (all->line[++i] && all->line[i] >= '0' && all->line[i] <= '9')
		;
	all->c_grass = all->line[i] ? all->line[i] : '\0';
	i++;
	all->c_tree = all->line[i] ? all->line[i] : '\0';
	i++;
	all->c_house = all->line[i] ? all->line[i] : '\0';
	return (!all->c_grass || !all->c_tree ||
		!all->c_house ? set_error(all, ERROR_MAP) : SUCCESS);
}

int			one_file_handle(t_all *all, char *filename)
{
	int		fd;
	char	init;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (set_error(all, ERROR_SYS));
	init = 0;
	if (init_map(all, fd) == FAILURE)
		return (set_error(all, ERROR_SYS));
	while (get_next_line(fd, &all->line))
	{
		if (!init)
		{
			all->size_line = ft_strlen(all->line);
			all->prev = try_malloc(sizeof(int) * all->size_line);
			all->curr = try_malloc(sizeof(int) * all->size_line);
			init = 1;
		}
		if (check_line(all) == FAILURE)
			return (FAILURE);
		process(all, all->line, select_prev(all), select_curr(all));
		all->swap = all->swap == 0 ? 1 : 0;
		all->y_curr++;
	}
	return (all->y_curr != all->nb_line ? set_error(all, ERROR_MAP) : fd);
}

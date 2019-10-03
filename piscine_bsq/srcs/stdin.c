/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:39:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/26 17:19:40 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		set_line(t_all *all)
{
	all->size_line = ft_strlen(all->line);
	all->prev = try_malloc(sizeof(int) * all->size_line);
	all->curr = try_malloc(sizeof(int) * all->size_line);
	return (1);
}

int		stdin_handle(t_all *all)
{
	char	init;
	int		fd;

	if ((fd = open(TMP_MAP, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		return (set_error(all, ERROR_SYS));
	init = 0;
	if (init_map(all, STDOUT) == FAILURE)
		return (set_error(all, ERROR_SYS));
	while (get_next_line(STDOUT, &all->line))
	{
		if (!init)
			init = set_line(all);
		if (check_line(all) == FAILURE)
			return (FAILURE);
		write(fd, all->line, all->size_line);
		write(fd, "\n", 1);
		process(all, all->line, select_prev(all), select_curr(all));
		all->swap = all->swap == 0 ? 1 : 0;
		all->y_curr++;
		if (ft_strfind(all->line, FT_EOF) != -1)
			break ;
	}
	return (all->y_curr != all->nb_line ? set_error(all, ERROR_MAP) : STDOUT);
}

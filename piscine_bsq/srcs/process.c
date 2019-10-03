/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 04:26:10 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/24 06:48:24 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			check_line(t_all *all)
{
	int		i;

	i = -1;
	while (all->line[++i])
		if (all->line[i] != all->c_grass && all->line[i] != all->c_tree)
			return (FAILURE);
	if (i != all->size_line)
		return (FAILURE);
	return (SUCCESS);
}

int			pascal(int top, int top_left, int left)
{
	if (left <= top && left <= top_left)
		return (left + 1);
	if (top <= left && top <= top_left)
		return (top + 1);
	if (top_left <= top && top_left <= left)
		return (top_left + 1);
	return (0);
}

void		process(t_all *all, char *line, int *prev, int *curr)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == all->c_tree)
			curr[i] = 0;
		else if (!i)
			curr[i] = pascal(prev[i], 0, 0);
		else
			curr[i] = pascal(prev[i], prev[i - 1], curr[i - 1]);
		if (curr[i] > all->max)
		{
			all->max = curr[i];
			all->x_max = i;
			all->y_max = all->y_curr;
		}
	}
}

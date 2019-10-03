/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 04:25:21 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 22:59:17 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			print_result(t_all *all, char *filename, int lever)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (FAILURE);
	line = NULL;
	if (lever == 1 && get_next_line(fd, &line) == -1)
		return (FAILURE);
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if (++i > all->y_max - all->max && i <= all->y_max)
		{
			j = -1;
			while (line[++j])
				write(1, j > all->x_max - all->max &&
					j <= all->x_max ? &all->c_house : &line[j], 1);
		}
		else
			write(1, line, all->size_line);
		write(1, "\n", 1);
	}
	return (SUCCESS);
}

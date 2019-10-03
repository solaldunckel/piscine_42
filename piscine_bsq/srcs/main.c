/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:25:15 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 23:05:47 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			error(t_all *all)
{
	if (all)
		write(2, "map error\n", 10);
	return (FAILURE);
}

void		close_fd(int *fd, int size)
{
	int		i;

	if (fd)
	{
		i = -1;
		while (++i < size)
			close(fd[i]);
	}
}

int			set_error(t_all *all, int err_no)
{
	all->err_no = err_no;
	return (FAILURE);
}

int			one_arg(void)
{
	t_all	*all;

	all = try_malloc(sizeof(t_all));
	if (stdin_handle(all) == FAILURE)
		return (FAILURE);
	if (print_result(all, TMP_MAP, 0) == FAILURE)
		error(all);
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_all	*all;
	int		i;
	int		*fd;

	fd = NULL;
	if (ac == 1 && one_arg() == FAILURE)
		return ((write(2, "map error\n", 10) * 0) - 1);
	else
	{
		i = 0;
		fd = try_malloc(sizeof(int) * ac);
		while (++i < ac)
		{
			all = try_malloc(sizeof(t_all));
			if ((fd[i] = one_file_handle(all, av[i])) == -1)
				error(all);
			else if (print_result(all, av[i], 1) == FAILURE)
				error(all);
			free_all(all);
			if (i + 1 < ac)
				write(1, "\n", 1);
		}
	}
	close_fd(fd, ac);
	return (0);
}

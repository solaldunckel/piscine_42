/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:30:59 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/24 15:43:53 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str, int std);
int		ft_atoi(char *str);
void	ft_print_name(char *str);

void	ft_puterror(char *str, int type, char *name)
{
	if (type == 0)
	{
		ft_putstr(basename(name), 2);
		ft_putstr(": ", 2);
		ft_putstr(str, 2);
		ft_putstr(": ", 2);
		ft_putstr(strerror(errno), 2);
		ft_putstr("\n", 2);
	}
	if (type == 2)
	{
		ft_putstr(basename(name), 2);
		ft_putstr(": option requires an argument -- c\n", 2);
	}
	if (type == 3)
	{
		ft_putstr(basename(name), 2);
		ft_putstr(": illegal offset -- ", 2);
		ft_putstr(str, 2);
		ft_putstr("\n", 2);
	}
}

void	ft_tail_loop(void)
{
	int		ret;
	char	buf[0];

	while ((ret = read(0, buf, 1)))
	{
	}
}

void	ft_display_file(char *str, int offset, int fd)
{
	int		ret;
	long	count;
	char	buf[2];
	int		count2;

	count2 = 0;
	count = 0;
	while ((ret = read(fd, buf, 1)))
		count++;
	if (close(fd) == -1)
		return ;
	fd = open(str, O_RDONLY);
	count = count - offset;
	while ((ret = read(fd, buf, 1)))
	{
		if (count2 >= count)
			ft_putstr(buf, 1);
		count2++;
	}
	if (close(fd) == -1)
		return ;
}

void	ft_tail_file(char *str, int offset, int multiple, char *name)
{
	int		fd;

	if ((fd = open(str, O_DIRECTORY)) == -1)
	{
		if ((fd = open(str, O_RDONLY)) == -1)
		{
			ft_puterror(str, 0, name);
			return ;
		}
		if (multiple)
		{
			ft_print_name(str);
		}
		ft_display_file(str, offset, fd);
	}
	else
	{
		if (multiple)
			ft_print_name(str);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		offset;

	i = 2;
	if (argc == 2)
	{
		ft_puterror("", 2, argv[0]);
		return (0);
	}
	if ((offset = ft_atoi(argv[2])) == -1)
	{
		ft_puterror(argv[2], 3, argv[0]);
		return (0);
	}
	if (offset >= 0 && argc == 3)
		ft_tail_loop();
	while (++i < argc)
	{
		if (i >= 4 && (!(open(argv[i], O_RDONLY) == -1)))
			ft_putstr("\n", 1);
		if (argc > 4)
			ft_tail_file(argv[i], offset, 1, argv[0]);
		else
			ft_tail_file(argv[i], offset, 0, argv[0]);
	}
}

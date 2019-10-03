/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 12:27:43 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/24 15:32:38 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str, int std)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

void	ft_puterror(char *str, int type, char *name)
{
	ft_putstr(basename(name), 2);
	ft_putstr(": ", 2);
	ft_putstr(str, 2);
	ft_putstr(": ", 2);
	if (type == 0)
		ft_putstr(strerror(errno), 2);
	else if (type == 1)
		ft_putstr("Is a directory", 2);
	ft_putstr("\n", 2);
}

void	ft_cat(void)
{
	int		ret;
	char	buf[0];

	while ((ret = read(0, buf, 1)))
		ft_putstr(buf, 1);
}

void	ft_display_file(char *str, char *name)
{
	int		fd;
	int		ret;
	char	buf[2];

	if ((fd = open(str, O_DIRECTORY)) == -1)
	{
		if ((fd = open(str, O_RDONLY)) == -1)
		{
			ft_puterror(str, 0, name);
			return ;
		}
		while ((ret = read(fd, buf, 1)))
			ft_putstr(buf, 1);
	}
	else
	{
		ft_puterror(str, 1, name);
		return ;
	}
	if (close(fd) == -1)
		return ;
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
		ft_cat();
	while (++i < argc)
		ft_display_file(argv[i], argv[0]);
	return (0);
}

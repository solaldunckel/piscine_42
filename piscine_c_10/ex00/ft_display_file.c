/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:34:42 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/25 18:57:41 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str, int std)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

void	ft_display_file(char *str)
{
	int		fd;
	int		ret;
	char	buf;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return ;
	}
	while ((ret = read(fd, &buf, 1)))
		write(1, &buf, 1);
	if (close(fd) == -1)
		return ;
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n", 2);
	else if (argc > 2)
		ft_putstr("Too many arguments.\n", 2);
	else
		ft_display_file(argv[1]);
	return (0);
}

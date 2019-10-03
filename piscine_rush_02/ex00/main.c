/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:31:57 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/23 20:39:18 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_arg(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	if (count > 39)
		return (0);
	return (1);
}

char	*read_input(void)
{
	int		ret;
	char	*buf;

	if (!(buf = malloc(sizeof(char*) * 100)))
		return (NULL);
	ret = read(0, buf, 100);
	return (buf);
}

void	free_memory(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		main(int argc, char **argv)
{
	char	**tab;
	char	*arg;

	if (argc > 2)
	{
		ft_putstr(ERROR);
		return (0);
	}
	if (argc == 2)
		arg = argv[1];
	if (argc == 1)
	{
		arg = read_input();
		if (ft_strlen(arg) > 1)
			arg[ft_strlen(arg) - 1] = '\0';
	}
	if (!check_arg(arg))
	{
		ft_putstr(ERROR);
		return (0);
	}
	tab = parse_dictionary();
	ft_print(arg, tab);
	free_memory(tab);
	return (0);
}

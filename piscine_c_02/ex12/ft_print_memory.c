/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:11:39 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/19 21:37:56 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_hex(unsigned int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[num / 16], 1);
	write(1, &hex[num % 16], 1);
}

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int		j;
	int		k;

	i = 0;
	ft_putstr(&addr);
	return (addr);
}

int		main(int argc, char **argv)
{

	if (argc != 2)
		return (0);
	ft_print_memory(argv[1], ft_strlen(argv[1]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:24:05 by exam              #+#    #+#             */
/*   Updated: 2019/06/07 18:36:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	int		i;
	char	c;
	char	print;

	i = 0;
	c = 'z';

	while(c >= 'a')
	{
		if (i % 2 == 0)
			print = c;
		else
			print = c - 32;
		write(1, &print, 1);
		c--;
		i++;
	}
	write(1, "\n", 1);
}



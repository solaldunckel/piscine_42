/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:33:54 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/24 13:44:49 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		i;
	int		j;
	int		mod;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (j < length)
	{
		mod = (*f)(tab[j]);
		if (mod != 0)
			count++;
		j++;
	}
	return (count);
}

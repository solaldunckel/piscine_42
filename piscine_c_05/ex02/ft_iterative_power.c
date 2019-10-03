/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 08:41:26 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/12 12:53:17 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		res;

	i = power;
	res = 1;
	if (power < 0)
		return (0);
	while (i > 0)
	{
		res = res * nb;
		i--;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:24:39 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/06 12:38:50 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		a_copy;
	int		b_copy;

	a_copy = *a;
	b_copy = *b;
	*a = a_copy / b_copy;
	*b = a_copy % b_copy;
}

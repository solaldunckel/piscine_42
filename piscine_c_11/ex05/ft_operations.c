/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:19:39 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/21 16:19:20 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long int	add(int nb1, int nb2)
{
	return (nb1 + nb2);
}

long int	sub(int nb1, int nb2)
{
	return (nb1 - nb2);
}

long int	divide(int nb1, int nb2)
{
	return (nb1 / nb2);
}

long int	multiply(int nb1, int nb2)
{
	return (nb1 * nb2);
}

long int	modulo(int nb1, int nb2)
{
	return (nb1 % nb2);
}

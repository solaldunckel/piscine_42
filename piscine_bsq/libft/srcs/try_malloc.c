/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:30:57 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/24 01:12:23 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*try_malloc(size_t size)
{
	void	*new;

	if ((new = malloc(size)) == NULL)
		exit(-1);
	return (ft_bzero(new, size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsize <tomsize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:04:30 by tomsize           #+#    #+#             */
/*   Updated: 2019/08/26 22:14:13 by tomsize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int 	ft_list_size(t_list *begin_list)
{
	int 	count;
	t_list 	*tmp;

	count = 0;
	tmp = begin_list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

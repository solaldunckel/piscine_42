/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsize <tomsize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:27:24 by tomsize           #+#    #+#             */
/*   Updated: 2019/08/26 22:03:51 by tomsize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void 		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list 		*list;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}

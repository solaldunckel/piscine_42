/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsize <tomsize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:26:15 by tomsize           #+#    #+#             */
/*   Updated: 2019/08/28 17:09:34 by tomsize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void 	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list 	*list;

	list = *begin_list;
	if (!list)
	{
		list = ft_create_elem(data);
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = ft_create_elem(data);
}

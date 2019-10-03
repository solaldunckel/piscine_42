/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsize <tomsize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:12:35 by tomsize           #+#    #+#             */
/*   Updated: 2019/08/26 22:24:37 by tomsize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list 	*ft_list_last(t_list *begin_list)
{
	t_list 		*list;

	list = begin_list;
	while (list->next)
		list = list->next;
	return (list);
}

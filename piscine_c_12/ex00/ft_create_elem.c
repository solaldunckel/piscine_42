/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsize <tomsize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:22:39 by tomsize           #+#    #+#             */
/*   Updated: 2019/08/26 19:25:03 by tomsize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list 		*ft_create_elem(void *data)
{
	t_list 		*element;

	if (!(element = malloc(sizeof(t_list))))
		return (NULL);
	element->data = data;
	element->next = NULL;

	return (element);
}

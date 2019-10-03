#include "list.h"

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list		*begin;
	t_list		*ptr;
	int			temp;
	
	temp = 0;
	begin = lst;
	while (lst)
	{
		ptr = lst->next;
		while (ptr)
		{
			if ((*cmp)(ptr->data, lst->data))
			{
				temp = lst->data;
				lst->data = ptr->data;
				ptr->data = temp;
			}
			ptr = ptr->next;
		}
		lst = lst->next;
	}
	return (begin);
}

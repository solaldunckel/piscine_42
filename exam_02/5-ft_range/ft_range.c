#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;
	
	i = 0;	
	if (start > end)
	{
		if (!(tab = malloc(sizeof(int) * (start - end + 1))))
			return (NULL);
		while (start >= end)
		{
			tab[i] = start;
			i++;
			start--;
		}
	}
	else if (start < end)
	{
		if (!(tab = malloc(sizeof(int) * (end - start + 1))))
			return (NULL);
		while (end >= start)
		{
			tab[i] = start;
			i++;
			start++;
		}
	}
	else 
	{
		if (!(tab = malloc(sizeof(int) + 1)))
			return (NULL);
		tab[i] = start;
	}	
	return (tab);
}

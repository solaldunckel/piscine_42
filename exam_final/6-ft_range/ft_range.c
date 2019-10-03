#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		i;
	int		*tab;

	i = 0;
	if (end > start)
	{	
		tab = malloc(sizeof(int) * (end - start) + 1);
		while (start <= end)
		{
			tab[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		tab = malloc(sizeof(int) * (start - end) + 1);
		while (end <= start)
		{
			tab[i] = start;
			start--;
			i++;
		}
	}
	return (tab);
}

#include <stdlib.h>

int		is_separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int		i;
	int		count;
	int		is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (str[i])
	{
		if (is_separator(str[i]))
			is_word = 0;
		else if (is_word == 0 && !is_separator(str[i]))
		{	
			is_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		word_size(char *str, int pos)
{
	int count;

	count = 0;
	while (str[pos])
	{
		if (is_separator(str[pos]))
			return (count);
		count++;
		pos++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	
	if (!(tab = malloc(sizeof(char*) * (count_words(str) + 2))))
		return (NULL);
	while (str[i])
	{	
		if (!is_separator(str[i]))
		{	
			if (k == 0)
			{
				if (!(tab[j] = malloc(sizeof(char) * (word_size(str, i) + 1))))
					return (NULL);
			}
			tab[j][k] = str[i];
			tab[j][k + 1] = '\0';
			k++;
			if (is_separator(str[i+1]))
			{
				k = 0;
				j++;
			}
		}
		i++;
	}
	if (!is_separator(str[i - 1]) && (ft_strlen(str) != 0))
		j++;
	tab[j] = NULL;
	return (tab);
}

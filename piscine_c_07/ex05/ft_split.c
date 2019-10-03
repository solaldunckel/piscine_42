/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:15:22 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/20 19:47:39 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_c(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int		count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (is_c(*str, charset))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		w_size(char *str, char *charset, int pos)
{
	int		i;

	i = 0;
	while (str[pos])
	{
		if (!is_c(str[pos], charset))
			i++;
		pos++;
	}
	return (i);
}

void	split_it(char **tab, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if (!is_c(str[i], charset))
		{
			if (k == 0)
				if (!(tab[j] = malloc(sizeof(char) *
				(w_size(str, charset, i) + 1))))
					return ;
			tab[j][k] = str[i];
			tab[j][k + 1] = '\0';
			k++;
		}
		if ((is_c(str[i], charset) && !is_c(str[i + 1], charset) && k > 0)
		&& (k = 0) == 0)
			j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	if (!(tab = malloc(sizeof(char*) * (ft_count_words(str, charset) + 1))))
		return (NULL);
	split_it(tab, str, charset);
	tab[ft_count_words(str, charset)] = NULL;
	return (tab);
}

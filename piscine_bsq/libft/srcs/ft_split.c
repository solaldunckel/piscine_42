/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:40:28 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 17:07:55 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_word(char *str, char *sep)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && ft_strfind(sep, str[i]) == -1)
		{
			ret++;
			while (str[i] && ft_strfind(sep, str[i]) == -1)
				i++;
		}
		while (str[i] && ft_strfind(sep, str[i]) != -1)
			i++;
	}
	return (ret);
}

char		**engine(char **ret, char *str, char *sep)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] && ft_strfind(sep, str[i]) == -1)
		{
			j = i;
			while (str[j] && ft_strfind(sep, str[j]) == -1)
				j++;
			if (!(ret[++k] = ft_strsub(str, i, j - i)))
				return (NULL);
		}
		i = j;
		while (str[i] && ft_strfind(sep, str[i]) != -1)
			i++;
	}
	return (ret);
}

char		**ft_split(char *str, char *sep)
{
	char	**ret;
	int		size;

	size = count_word(str, sep);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	return (engine(ret, str, sep));
}

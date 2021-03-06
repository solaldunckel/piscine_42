/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:39:33 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/24 15:08:19 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] & s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[j - 1], tab[i]) > 0)
			{
				temp = tab[j - 1];
				tab[j - 1] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

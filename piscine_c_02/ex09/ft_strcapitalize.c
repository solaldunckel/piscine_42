/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:55:03 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/07 13:14:51 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		set_upper;

	i = 0;
	set_upper = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (set_upper && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!set_upper && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			set_upper = 0;
		}
		else
			set_upper = 1;
		i++;
	}
	return (str);
}

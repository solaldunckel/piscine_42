/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:30:15 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/23 17:12:29 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define ERROR "Error\n"
# define DICT_FILE "numbers.dict"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_total(char *str);
int		check_arg(char *str);
char	**parse_dictionary(void);
void	ft_print(char *str, char **tab);
char	*ft_split(char *tab);
int		zero_check(char *str);

#endif

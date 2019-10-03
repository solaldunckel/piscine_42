/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:05:37 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 14:01:00 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# define BUFF_SIZE	65535

char		**ft_split(char *str, char *sep);
void		*ft_bzero(void *s, int n);
void		*try_malloc(size_t size);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strsub(char *s, int start, int len);
int			ft_atoi(const char *str);
int			ft_strfind(char *str, char c);
int			ft_strlen(char *str);
void		ft_putstr(char *s);
void		ft_strdel(char **as);
void		ft_memdel(void **p);
#endif

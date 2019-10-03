/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:26:12 by sdunckel          #+#    #+#             */
/*   Updated: 2019/06/21 16:20:23 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

long int	add(int nb1, int nb2);
long int	sub(int nb1, int nb2);
long int	divide(int nb1, int nb2);
long int	multiply(int nb1, int nb2);
long int	modulo(int nb1, int nb2);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_putnbr(long int nb);
int			ft_atoi(char *str);

#endif

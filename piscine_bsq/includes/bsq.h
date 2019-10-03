/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:12:59 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 22:59:11 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFF_SIZE	65535
# define FAILURE	-1
# define SUCCESS	0
# define ERROR_SYS	0
# define ERROR_MAP	1
# define STDOUT		0
# define FT_EOF		'\04'
# define TMP_MAP	"tmp_map"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_all
{
	char			*line;
	int				*prev;
	int				*curr;
	int				x_max;
	int				y_max;
	int				y_curr;
	int				max;
	char			swap;
	char			c_grass;
	char			c_tree;
	char			c_house;
	int				size_line;
	int				nb_line;
	int				err_no;
}					t_all;

int					one_file_handle(t_all *all, char *filename);
void				process(t_all *all, char *line, int *prev, int *curr);
int					print_result(t_all *all, char *filename, int lever);
void				free_all(t_all *all);
int					*select_prev(t_all *all);
int					*select_curr(t_all *all);
int					check_line(t_all *all);
int					error(t_all *all);
int					set_error(t_all *all, int err_no);
int					stdin_handle(t_all *all);
int					init_map(t_all *all, int fd);
#endif

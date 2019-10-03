/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:43:38 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/26 14:00:53 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE	65535
# define ERROR		-1
# define RET_LINE	1
# define FINISH		0

typedef struct		s_str
{
	char			*str;
	int				fd;
	struct s_str	*next;
}					t_str;
int					get_next_line(const int fd, char **line);
#endif

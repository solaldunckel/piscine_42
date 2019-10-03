# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/23 16:03:01 by tharchen          #+#    #+#              #
#    Updated: 2019/06/24 06:12:46 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPILATOR - FLAGS ************************************************** #
NAME			=	libft.a
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

# INCLUDES ******************************************************************* #
INCLUDES_DIR	=	includes

# SRCS *********************************************************************** #
SRCS_LIST		=	\
					ft_atoi.c			\
					ft_bzero.c			\
					ft_putstr.c			\
					ft_split.c			\
					ft_strdel.c			\
					ft_memdel.c			\
					ft_strdup.c			\
					ft_strfind.c		\
					ft_strjoin.c		\
					ft_strlen.c			\
					ft_strsub.c			\
					try_malloc.c		\
					get_next_line.c		\

SRCS_DIR		=	srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# OBJS *********************************************************************** #
OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_DIR		=	objs/
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# RULES ********************************************************************** #

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(GCC) $(FLAGS) -I $(INCLUDES_DIR) -c -o $@ $^

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

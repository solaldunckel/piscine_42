# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 16:15:12 by tharchen          #+#    #+#              #
#    Updated: 2019/06/26 23:06:58 by sdunckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPILATOR - FLAGS - LIBFT ****************************************** #
NAME			=	bsq
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
LIBFT_DIR		=	libft/
LIBFT_LIB		=	libft.a
LIBFT			=	$(addprefix $(LIBFT_DIR), $(LIBFT_LIB))

# INCLUDES ******************************************************************* #
INCLUDES_DIR	=	includes

# SRCS *********************************************************************** #
SRCS_LIST		=	\
					main.c				\
					file_handle.c		\
					process.c			\
					print_result.c		\
					stdin.c				\

SRCS_DIR		=	srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# OBJS *********************************************************************** #
OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_DIR		=	objs/
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# RULES ********************************************************************** #

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(SRCS)
	@make --no-print-directory -C $(LIBFT_DIR)
	@$(GCC) $(FLAGS) -I $(INCLUDES_DIR) $(LIBFT) -o $@ $^

clean :
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf tmp_map

fclean : clean
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all

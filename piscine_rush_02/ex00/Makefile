NAME	= rush-02
SRCS	= main.c ft_f.c dictionary.c ft_print.c ft_split.c
OBJS	= ${SRCS:.c=.o}
HEADER	= ft.h

CC		= cc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

${NAME}:	${SRCS}
			${CC} -c ${CFLAGS} ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		clean
			fclean
			all
			re

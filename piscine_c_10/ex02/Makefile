NAME	= ft_tail
SRCS	= ft_tail.c ft_f.c
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

all:		${SRCS}
			${CC} -c ${CFLAGS} ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

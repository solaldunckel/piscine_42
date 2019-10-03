NAME	= do-op
SRCS	= ft_operations.c ft_f.c do_op.c
OBJS	= ${SRCS:.c=.o}
HEADER	= ft.h

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

all:		${SRCS}
			${CC} -c ${CFLAGS} ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

NAME	= ft_display_file
SRCS	= ft_display_file.c
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

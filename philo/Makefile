# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 16:11:26 by ytouab            #+#    #+#              #
#    Updated: 2022/08/20 21:09:46 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

OBJS		= ${SRC:.c=.o}

WHITE		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"

RM			=	rm -f

CC		=	gcc

CF		=	-Wall -Wextra -Werror

TH		=	-pthread

SRCS		=	srcs/parse.c \
				srcs/print.c \
				srcs/tools.c \
				srcs/events.c \


SRC			=	philosophers.c \
				${SRCS} \



.c.o:
		@${CC} ${CF} ${TH} -c $< -o ${<:.c=.o}


$(NAME):	${OBJS}
		@${CC} ${CF} ${TH} ${OBJS} -o ${NAME}
		@echo ${GREEN}"Compilation Done ✅"

all:	${NAME}

clean:
		@${RM} ${OBJS}
		@echo ${RED}"Object Files Deleted ✅"${WHITE}

fclean:	clean
		@${RM} ${NAME}
		@echo ${RED}"Executable File Deleted ✅"${WHITE}

re:		fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 18:56:06 by gothmane          #+#    #+#              #
#    Updated: 2023/03/13 20:12:08 by gothmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_M = philo.c philo_utils.c  philo_utils2.c routines.c init.c cleaner.c time.c

OBJS_M = ${SRCS_M:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = philo

$(NAME): $(OBJS_M)
			${CC} ${Flags}  -o $@ $^

all : 	$(NAME)

clean:
		${RM} -f $(OBJS_M) 

fclean:  clean
		${RM} -f $(NAME)

re: fclean all

.phony: all clean fclean re 
##
## EPITECH PROJECT, 2018
## malloc.h
## File description:
## philosopher
##

CC		=	gcc

NAME		=	philo

SRC		=	srcs/main.c\
			srcs/utils.c\
			srcs/philo.c\
			srcs/thread.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-I./includes/ -L. -lriceferee -Wall -Wextra  -W -Wall -Wextra 

LDFLAGS 	=	-lpthread

RM		=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

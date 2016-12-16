##
## Makefile for Makefile in /home/pierre/work/Unix_System/PSU_2016_my_popup/
##
## Made by Pierre Narcisi
## Login   <pierre.narcisi@epitech.eu>
##
## Started on  Tue Dec  6 12:26:51 2016 Pierre Narcisi
## Last update Fri Dec 16 14:32:23 2016 Pierre Narcisi
##

SRC	=	my_sokoban.c	\
			mouv.c				\
			verf.c

OBJS	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJS)
					gcc -g3 $(OBJS) -o $(NAME) -lncurses

clean:
			rm -f $(OBJS)

fclean:	clean
				rm -f $(NAME)

re:	fclean	$(NAME)

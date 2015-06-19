##
## Makefile for ascii-deminor in /home/aracthor/programs/projects/ascii-deminor
## 
## Made by Aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Fri Jun 19 10:46:13 2015 Aracthor
## Last Update Fri Jun 19 10:53:29 2015 Aracthor
##

CC=	gcc

RM=	rm -f

INSTALL=install

PREFIX=	/usr/local


NAME=	ascii-deminor

SRCS=	coord.c		\
	cursor.c	\
	display.c	\
	events.c	\
	grid.c		\
	main.c		\
	mooves.c	\
	select.c	\
	termcaps.c

OBJS=	$(SRCS:%.c=%.o)


CFLAGS=	-Wall -Werror -Wextra	\
	-ansi -pedantic		\
	-D_BSD_SOURCE

LDFLAGS=-o $(NAME)



$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

install:	$(NAME)
		$(INSTALL) -m 0755 $(NAME) $(PREFIX)/bin

re:		fclean all

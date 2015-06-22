##
## Makefile for ascii-deminor in /home/aracthor/programs/projects/ascii-deminor
## 
## Made by Aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Fri Jun 19 10:46:13 2015 Aracthor
## Last Update Mon Jun 22 14:25:45 2015 Aracthor
##

CC=	gcc

RM=	rm -f

MKDIR=	mkdir

INSTALL=install

PREFIX=		/usr/local
BIN_DIR=	$(PREFIX)/bin
MAN_DIR=	$(PREFIX)/man
MAN_SUBDIR=	$(MAN_DIR)/man6


NAME=	ascii-minesweeper

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

MAN=	man/ascii-minesweeper.6


CFLAGS=	-Wall -Werror -Wextra	\
	-ansi -pedantic		\
	-D_BSD_SOURCE

LDFLAGS=-o $(NAME)



$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS)

$(MAN_SUBDIR):
		$(MKDIR) $(MAN_SUBDIR)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

install:	$(NAME) $(MAN_SUBDIR)
		$(INSTALL) -m 0755 $(NAME) $(BIN_DIR)
		$(INSTALL) -m 0644 $(MAN) $(MAN_SUBDIR)

re:		fclean all

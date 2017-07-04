##
## Makefile for  in /home/da-pur_c/delivery/Maths/101pong
## 
## Made by Clem Da
## Login   <da-pur_c@epitech.net>
## 
## Started on  Mon Nov  7 09:34:43 2016 Clem Da
## Last update Tue Nov 15 15:23:00 2016 Hugo WALTER
##

NAME	=	pong

SRC	=	pong.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-I.

LDFLAGS =	-lc_graph_prog -lm

RM	=	rm -rf

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

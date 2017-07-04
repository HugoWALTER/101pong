##
## Makefile for  in /home/da-pur_c/delivery/Maths/101pong
## 
## Made by Clem Da
## Login   <da-pur_c@epitech.net>
## 
## Started on  Mon Nov  7 09:34:43 2016 Clem Da
## Last update Tue Nov  8 20:25:09 2016 Hugo WALTER
##

NAME=	101pong

SRC=	101pong.c

INC=	-I.

OBJ=	$(SRC:.c=.o)

CC=	gcc -lm

CFLAGS=	$(INC) $(LIB)

RM=	rm -rf

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

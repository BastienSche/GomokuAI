##
## Makefile for my_ftp
## 
## Bastien SCHEKTMAN
##

SERVER_SRCS	= 	src/*.cpp

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)

CC		= g++

RM		= rm -rf

SERVER_NAME	= pbrain-gomoku-ai

all:		$(SERVER_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
		$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS)

fclean:		clean
		$(RM) $(SERVER_NAME)

re:		fclean all

.PHONY:		all clean fclean re
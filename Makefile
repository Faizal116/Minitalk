SRCS = server.c client.c
OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client


server: server.o libft
		$(CC) -o $@ $< -Llibft -lft

client: client.o libft
		$(CC) -o $@ $< -Llibft -lft

%.o: %.c
		$(CC) -c $(CFLAGS) $?

libft:
		make -C libft

clean: 
		rm -f $(OBJS)
		rm -f *.o
		make -C libft clean
	
fclean: clean
		rm -f server client libft/libft.a

re: 	fclean all

.PHONY: all bonus libft clean fclean re
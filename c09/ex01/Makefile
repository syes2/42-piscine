CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCLUDES = includes
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	fclean all

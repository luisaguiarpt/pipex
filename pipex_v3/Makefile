CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCL=libft

SRCS=exit.c \
	 free.c \
	 init.c \
	 parse_argv.c \
	 parse_envp.c \
	 pipex.c

OBJS=$(SRCS:%.c=%.o)
B_OBJS=$(B_SRCS:%.c=%.o)

LIBFT=libft/libft.a
NAME=pipex

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCL)

$(LIBFT):
	make -C libft/ all

clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

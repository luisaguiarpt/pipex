CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCL=libft

SRCS=pipex.c \
	 utils.c
B_SRCS=pipex_bonus.c \
	   utils_bonus.c

OBJS=$(SRCS:%.c=%.o)
B_OBJS=$(B_SRCS:%.c=%.o)

LIBFT=libft/libft.a
NAME=pipex

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

bonus: $(LIBFT) $(B_OBJS)
	$(CC) $(FLAGS) $(B_OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCL)

$(LIBFT):
	make -C libft/ all

clean:
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

CC=cc
FLAGS=-Wall -Wextra -Werror -g

LIBFTDIR=libft
LIBFTINC=$(LIBFTDIR)/libft.h
LIBFTSRC=ft_abs.c ft_atod.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
		 ft_free_tab.c \
		 ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isdouble.c ft_isint.c \
		 ft_isprint.c ft_itoa.c ft_lstadd_back.c \
		 ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		 ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_max.c \
		 ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_sqrt.c ft_split.c \
		 ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		 ft_strlcat.c \
		 ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIBFTSRCS=$(addprefix $(LIBFTDIR)/, $(LIBFTSRC))
LIBFTO=$(LIBFTSRCS:.c=.o)

GNLDIR=get_next_line
GNLINC=$(GNLDIR)/get_next_line.h
GNLSRC=get_next_line.c get_next_line_utils.c
GNLSRCS=$(addprefix $(GNLDIR)/, $(GNLSRC))
GNLO=$(GNLSRCS:.c=.o)

PRINTFDIR=ft_printf
PRINTFINC=$(PRINTFDIR)/includes
PRINTFSRC=ft_nbrsize.c ft_printf.c ft_printf_parsers.c \
		  ft_printf_parser_utils.c ft_printf_utils.c pos_diff.c \
		  putchar_format.c puthex_format.c putnbr_format.c putnbr_u_format.c \
		  putptr_format.c putstr_format.c
PRINTFSRCS=$(addprefix $(PRINTFDIR)/srcs/, $(PRINTFSRC))
PRINTFO=$(PRINTFSRCS:.c=.o)

NAME=libft.a

all: $(NAME)

$(LIBFTDIR)/%.o: $(LIBFTDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTFDIR)/%.o: $(PRINTFDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(PRINTFINC)

$(GNLDIR)/%.o: $(GNLDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFTO) $(GNLO) $(PRINTFO)
	ar rcs $(NAME) $(LIBFTO) $(GNLO) $(PRINTFO)

clean:
	rm -f $(LIBFTO) $(PRINTFO) $(GNLO)

fclean: clean
	rm -f $(NAME)

re: fclean all

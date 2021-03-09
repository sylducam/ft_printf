NAME = libftprintf.a
HEADER = ./ft_printf.h

LIBAR = libft/libft.a
LIBHEADER = libft/libft.h

SRCS= ./ft_printf.c\
	./ft_parser.c\
	./ft_displayer.c\
	./ft_utils.c\
	./displayer/ft_display_char.c\
	./displayer/ft_display_hexa.c\
	./displayer/ft_display_nbr.c\
	./displayer/ft_display_percent.c\
	./displayer/ft_display_ptr.c\
	./displayer/ft_display_str.c\
	./displayer/ft_display_u.c

LIBSRCS= ./ft_atoi.c\
	./ft_bzero.c\
	./ft_isalnum.c\
	./ft_isalpha.c\
	./ft_isascii.c\
	./ft_isdigit.c\
	./ft_isprint.c\
	./ft_memcpy.c\
	./ft_memccpy.c\
	./ft_memcmp.c\
	./ft_memset.c\
	./ft_memchr.c\
	./ft_memmove.c\
	./ft_strlen.c\
	./ft_strlcpy.c\
	./ft_strlcat.c\
	./ft_strncmp.c\
	./ft_strchr.c\
	./ft_tolower.c\
	./ft_toupper.c\
	./ft_strdup.c\
	./ft_calloc.c\
	./ft_substr.c\
	./ft_strjoin.c\
	./ft_strnstr.c\
	./ft_putchar_fd.c\
	./ft_putstr_fd.c\
	./ft_putendl_fd.c\
	./ft_putnbr_fd.c\
	./ft_split.c\
	./ft_strmapi.c\
	./ft_strtrim.c\
	./ft_itoa.c\
	./ft_strrchr.c\
	./ft_strnlen.c\
	./ft_lstadd_back_bonus.c\
	./ft_lstadd_front_bonus.c\
	./ft_lstclear_bonus.c\
	./ft_lstdelone_bonus.c\
	./ft_lstiter_bonus.c\
	./ft_lstlast_bonus.c\
	./ft_lstmap_bonus.c\
	./ft_lstnew_bonus.c\
	./ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o) $(addprefix libft/, $(LIBSRCS:.c=.o))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c $(HEADER) $(LIBHEADER)
		@gcc -I $(HEADER) -I $(LIBHEADER) -c $< -o $@ $(FLAGS)
		@printf "*"

$(NAME): $(OBJS)
		@make -C libft
		@cp $(LIBAR) $(NAME)
		@ar rcs $(NAME) $(OBJS) $(LIBAR)
		@echo "ok boss"

clean:
		@rm -rf $(OBJS)
		@make clean -C libft
		@echo "cleaned"

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C libft
		@echo "cleaned"

re:		fclean all

.PHONY : all clean fclean re

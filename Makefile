NAME = libftprintf.a
CC = gcc
CFLAGS = 

SRCS = 	libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strnstr.c \
		libft/ft_strncmp.c \
		libft/ft_atoi.c \
		libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_calloc.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strmapi.c \
		libft/ft_strlen.c \
		ft_printf.c \
		srcs/bundle/ft_putstr_len_fd.c \
		srcs/bundle/ft_atoi_count.c \
		srcs/parsing/parsing.c \
		srcs/format/format.c \
		srcs/display/ft_display_int.c \
		srcs/bundle/width_nb.c \
		srcs/display/ft_display_c.c \
		srcs/display/ft_display_unsigned_int.c \
		srcs/bundle/ft_unsigned_itoa.c \
		srcs/display/ft_display_pointer.c \
		srcs/bundle/ft_putpointer_fd.c \
		srcs/display/ft_display_string.c \
		srcs/display/ft_display_hexa.c \
		srcs/bundle/ft_putpointer_maj.c \
		srcs/display/ft_display_percent.c
OBJS  = ${SRCS:.c=.o}
AR = ar rc
all: $(NAME)
	echo $(SRCS)

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	rm -rf $(OBJS)
	rm $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
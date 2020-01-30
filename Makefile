NAME = libftprintf.a
CC = gcc
CFLAGS =  -Wall -Wextra  $(INCLUDES)
INCLUDES += $(foreach d, $(INC_PATHS), -I $d)
INC_PATHS = libft .
SRCS = 	ft_printf.c \
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
		srcs/display/ft_display_string.c

OBJS  = ${SRCS:.c=.o}
AR  = ar rcs

all: $(OBJS) $(NAME) libft.a
	echo $(SRCS)
libft.a: 
	make -C libft
$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}  libft/libft.a $?
test: all
	$(CC) $(CFLAGS) main.c libftprintf.a libft/libft.a -o X
	./X
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
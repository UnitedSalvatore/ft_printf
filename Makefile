NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = ft_handle_char.c \
			ft_handle_string.c \
			ft_handle_int.c \
			ft_handle_ouxp.c \
			ft_handle_num.c \
			\
			ft_handle_conversion.c \
			ft_parse_specification.c \
			ft_add_to_buf.c \
			ft_put_width.c \
			ft_printf.c

SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./libft/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFT_DIR)/obj/*.o
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)/

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/
	make -C $(LIBFT_DIR)/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

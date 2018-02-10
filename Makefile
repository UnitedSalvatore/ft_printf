NAME = libftprintf.a

FILENAMES = ft_add_to_buf.c \
			ft_printf.c \
			main.c


SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./ -I./libft/

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(FLAGS) $(OBJECTS)

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

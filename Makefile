CC = gcc -Wall -Wextra -Werror

NAME = psv

SRC_DIR = src

INCLUDE_DIR = ./include

LIBFT_DIR = ./libft
MINILBX_DIR = ./mlx

MINILBX = $(MINILBX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(shell find $(SRC_DIR) -type f -name *.c)

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(MINILBX):
	$(MAKE) -C $(MINILBX_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(MINILBX) $(LIBFT)
	$(CC) $(OBJ) $(MINILBX) $(LIBFT) -lm -lX11 -lXext  -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = cub3d
INCL_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build

MLX = -lmlx -lX11 -lXext -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = main.c

SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCL_DIR)
RLFLAGS = -lreadline

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) $(MLX) $(RLFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean reNAME
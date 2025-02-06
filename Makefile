NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)
RLFLAGS = -lreadline
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = build

MLX = -lmlx -lX11 -lXext -lm

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HANDLE_KEY_NAMES = handle_key.c
HANDLE_KEY_DIR = handle_key
HANDLE_KEY_SRCS =  $(addprefix $(HANDLE_KEY_DIR)/, $(HANDLE_KEY_NAMES))

SRC_NAMES = $(HANDLE_KEY_SRCS)
ENDPOINT_NAME = main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SRC_DIR)/, $(ENDPOINT_NAME))

OBJ = $(patsubst %,$(OBJ_DIR)/%,$(SRC_NAMES:.c=.o))
ENDPOINT_OBJ = $(OBJ_DIR)/$(ENDPOINT_NAME:.c=.o)

all: pre $(NAME)

pre:
	@cd libft && make all

$(NAME): $(OBJ) $(ENDPOINT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ)  $(ENDPOINT_OBJ) $(LIBFT) $(MLX) $(RLFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Create necessary subdirectories
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(HANDLE_KEY_DIR)  # Ensure handle_key directory exists

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re

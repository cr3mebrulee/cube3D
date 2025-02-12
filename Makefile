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

DESTRUCTOR_KEY_NAMES = free_utils.c
DESTRUCTOR_KEY_DIR = destructor
DESTRUCTOR_KEY_SRCS =  $(addprefix $(DESTRUCTOR_KEY_DIR)/, $(DESTRUCTOR_KEY_NAMES))

PARSE_FILE_NAMES = parser.c parser_utils.c init_structs.c\
				parse_map.c map_validity.c\
				map_validity_2.c set_player.c process_line.c\
				pad_map.c put_C_F_color.c color_utils.c\
				color_utils_2.c
PARSE_FILE_DIR = parse_file
PARSE_FILE_SRCS =  $(addprefix $(PARSE_FILE_DIR)/, $(PARSE_FILE_NAMES))

SRC_NAMES = $(HANDLE_KEY_SRCS) $(PARSE_FILE_SRCS) $(DESTRUCTOR_KEY_SRCS)
# ENDPOINT_NAME = main.c
ENDPOINT_NAME = main_parser.c

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

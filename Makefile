NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)
RLFLAGS = -lreadline
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = build
PREFIX = @

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG
endif

MLX = -lmlx -lX11 -lXext -lm

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HANDLE_KEY_NAMES = handle_key.c calculate_new_positions.c
HANDLE_KEY_DIR = handle_key
HANDLE_KEY_SRCS =  $(addprefix $(HANDLE_KEY_DIR)/, $(HANDLE_KEY_NAMES))

INIT_MLX_DATA_NAMES = initialize_player.c initialize_mlx_data.c
INIT_MLX_DATA_DIR = initialize_mlx_data
INIT_MLX_DATA_SRCS =  $(addprefix $(INIT_MLX_DATA_DIR)/, $(INIT_MLX_DATA_NAMES))

DESTRUCTOR_NAMES = free_utils.c
DESTRUCTOR_DIR = destructor
DESTRUCTOR_SRCS =  $(addprefix $(DESTRUCTOR_DIR)/, $(DESTRUCTOR_NAMES))

PARSE_FILE_NAMES = parser.c parser_utils.c parser_utils_2.c init_structs.c init_structs_utils.c parse_map.c map_validity.c map_validity_2.c set_player.c process_line.c pad_map.c set_C_F_color.c color_utils.c color_utils_2.c set_texture.c set_texture_utils.c set_texture_utils_2.c
PARSE_FILE_DIR = parse_file
PARSE_FILE_SRCS =  $(addprefix $(PARSE_FILE_DIR)/, $(PARSE_FILE_NAMES))

SRC_NAMES = $(PARSE_FILE_SRCS) $(DESTRUCTOR_SRCS) $(HANDLE_KEY_SRCS) opts_fill.c $(INIT_MLX_DATA_SRCS)
ENDPOINT_NAME = main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SRC_DIR)/, $(ENDPOINT_NAME))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
ENDPOINT_OBJ = $(OBJ_DIR)/$(ENDPOINT_NAME:.c=.o)

all: pre $(NAME)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJ) $(ENDPOINT_OBJ) $(LIBFT)
	$(PREFIX)$(CC) $(CFLAGS) $(OBJ)  $(ENDPOINT_OBJ) $(LIBFT) $(MLX) $(RLFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(PREFIX)mkdir -p $(dir $@)
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(PREFIX)mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(HANDLE_KEY_DIR) $(OBJ_DIR)/$(INIT_MLX_DATA_DIR)

$(LIBFT):
	$(PREFIX)make -C $(LIBFT_DIR)

clean:
	$(PREFIX)rm -rf $(OBJ_DIR)
	$(PREFIX)cd $(LIBFT_DIR) && make clean

fclean: clean
	$(PREFIX)rm -f $(NAME)
	$(PREFIX)cd $(LIBFT_DIR) && make fclean

re: fclean all

debug: DEBUG = 1
debug: all

.PHONY: all clean fclean re

########################################
#            TANIA MODE                #
########################################

TANIA_OBJ_DIR = $(OBJ_DIR)/tania
TANIA_ENDPOINT_NAME = main_tania.c
TANIA_ENDPOINT_SRC = $(addprefix $(SRC_DIR)/, $(TANIA_ENDPOINT_NAME))
TANIA_ENDPOINT_OBJ = $(TANIA_OBJ_DIR)/$(TANIA_ENDPOINT_NAME:.c=.o)

# Include all necessary sources for Tania
TANIA_SRC_NAMES = $(PARSE_FILE_SRCS) $(DESTRUCTOR_SRCS) $(HANDLE_KEY_SRCS) $(INIT_MLX_DATA_SRCS)
TANIA_SRC = $(addprefix $(SRC_DIR)/, $(TANIA_SRC_NAMES))
TANIA_OBJ = $(patsubst $(SRC_DIR)/%.c, $(TANIA_OBJ_DIR)/%.o, $(TANIA_SRC))

# Ensure Tania's build directories exist
$(TANIA_OBJ_DIR):
	$(PREFIX)mkdir -p $(TANIA_OBJ_DIR) \
		$(TANIA_OBJ_DIR)/$(PARSE_FILE_DIR) \
		$(TANIA_OBJ_DIR)/$(DESTRUCTOR_KEY_DIR) \
		$(TANIA_OBJ_DIR)/$(HANDLE_KEY_DIR) \
		$(TANIA_OBJ_DIR)/$(INIT_MLX_DATA_DIR)

# Rule to compile source files into corresponding object files
$(TANIA_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(TANIA_OBJ_DIR)
	$(PREFIX)mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(PREFIX)$(CC) $(CFLAGS) -c $< -o $@

# Tania-specific build rule
tania: pre $(TANIA_OBJ_DIR) $(TANIA_OBJ) $(TANIA_ENDPOINT_OBJ) $(LIBFT)
	$(PREFIX)$(CC) $(CFLAGS) $(TANIA_OBJ) $(TANIA_ENDPOINT_OBJ) $(LIBFT) $(MLX) $(RLFLAGS) -o $(NAME)_tania

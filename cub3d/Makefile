NAME = cub3D

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libs/

INCLUDES = -I$(INC_DIR)

CC = gcc
FLAGS = -g

MLX_DIR = $(LIB_DIR)/opengl
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

FILES = cub3d \
		ft_bmp \
		ft_color_utils \
		ft_errors \
		ft_floor_n_ceiling \
		ft_map \
		ft_parser \
		ft_prepare \
		ft_rays_utils \
		ft_render_utils \
		ft_sprite_utils \
		ft_texture \
		ft_validate \

SRC_FILES = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES)))

OBJ_FILES = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES)))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -g

$(OBJ_FILES): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_FILES)
	@echo "All object files have been removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all

bonus: all

run: re 
	./cub3D maps/map.cub

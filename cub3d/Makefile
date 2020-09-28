NAME = cub3D

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libs/
B_SRC_DIR = bonus/src/
B_OBJ_DIR = bonus/obj/
B_INC_DIR = bonus/includes/

INCLUDES = -I$(INC_DIR)

BONUS_INCLUDES = -I$(B_INC_DIR)

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

BONUS_SRC = $(addsuffix _bonus.c, $(addprefix $(B_SRC_DIR), $(FILES)))

BONUS_OBJ = $(addsuffix _bonus.o, $(addprefix $(B_OBJ_DIR), $(FILES)))


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(OBJ_FILES): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(BONUS_OBJ): $(B_OBJ_DIR)%.o : $(B_SRC_DIR)%.c
	@$(CC) $(FLAGS) $(BONUS_INCLUDES) -c $< -o $@

$(B_OBJ_DIR):
	@mkdir $(B_OBJ_DIR)

clean:
	@rm -rf $(OBJ_FILES) $(BONUS_OBJ)
	@rm -f screenshot.bmp
	@echo "All object files have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) has been removed"

bonus: fclean $(B_OBJ_DIR) $(BONUS_OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(BONUS_INCLUDES) $(BONUS_OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS)

run: re 
	./cub3D maps/map.cub

runbonus: rebonus
	./cub3D maps/bonus.cub

re: fclean all

rebonus: fclean bonus

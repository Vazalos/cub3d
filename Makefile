# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:49:08 by david-fe          #+#    #+#              #
#    Updated: 2025/10/09 13:20:06 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
RM = rm -rf
CC_FLAGS = -Wall -Werror -Wextra -g
LINK_FLAGS = -lXext -lX11 -lm
O_FLAG = 0

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, main.c inits.c frees.c events.c draw.c \
color_utils.c raycast.c render.c print.c move.c raycast_dist.c raycast_textures.c \
minimap.c)
OBJ_PATH = .build
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: $(NAME)

# Build the libft library
$(LIBFT):
	@if [ ! -d $(LIBFT_PATH) ]; then make get_libft; fi

get_libft:
	@echo "$(CYA)Cloning libft...$(D)"
	@git clone --quiet git@github.com:PTGus/libft.git
	@echo "$(GRN)[LIBFT CLONED]$(D)"
	@$(MAKE) --silent -C $(LIBFT_PATH)

# Build the mlx library
$(MLX):
	@if [ ! -d $(MLX_PATH) ]; then make get_mlx; fi

get_mlx:
	@echo "$(CYA)Cloning mlx...$(D)"
	@git clone --quiet git@github.com:42paris/minilibx-linux.git $(MLX_PATH);
	@echo "$(GRN)[MLX CLONED]$(D)"
	@$(MAKE) --silent -C $(MLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@
	
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(LINK_FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

l: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Clean object files
clean:
	@if [ -d "$(BUILD_PATH)" ]; \
		then echo "$(RED)[REMOVED OBJECT FILES]$(END)"; \
		else echo "$(YEL)[NO OBJECTS TO CLEAN]$(END)"; \
	fi
	@$(RM) $(BUILD_PATH)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) --silent -C $(LIBFT_PATH) clean; \
	fi
	@if [ -d $(MLX_PATH) ]; then \
		$(MAKE) --silent -C $(MLX_PATH) clean; \
	fi

# Full clean
fclean: clean
	@if [ -f "$(NAME)" ]; \
		then echo "$(RED)[REMOVED EXECUTABLE]$(END)"; \
		$(RM) $(NAME) ; \
		else echo "$(YEL)[EXECUTABLE ALREADY CLEANED]$(END)"; \
	fi
	@if [ -d "$(LIBFT_PATH)" ]; \
		then echo "$(RED)[REMOVED LIBFT]$(END)"; \
		$(RM) $(LIBFT_PATH) ; \
		else echo "$(YEL)[LIBFT ALREADY CLEANED]$(END)"; \
	fi
	@if [ -d "$(MLX_PATH)" ]; \
		then echo "$(RED)[REMOVED MLX]$(END)"; \
		$(RM) $(MLX_PATH) ; \
		else echo "$(YEL)[MLX ALREADY CLEANED]$(END)"; \
	fi

re: fclean all


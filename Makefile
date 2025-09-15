# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:49:08 by david-fe          #+#    #+#              #
#    Updated: 2025/09/15 15:24:06 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
RM = rm -rf
CC_FLAGS = -Wall -Werror -Wextra -g
LINK_FLAGS = -lXext -lX11 -lm

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, main.c inits.c frees.c events.c draw.c color_utils.c calcs.c)
OBJ_PATH = .build
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = mlx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a

all: $(NAME)

$(LIBFT):
	@if [ ! -d $(LIBFT_PATH) ]; then \
		git clone git@github.com:PTGus/libft.git $(LIBFT_PATH); \
		$(MAKE) --silent -C $(LIBFT_PATH); \
	fi

$(MLX):
	@if [ ! -d $(MLX_PATH) ]; then \
		git clone git@github.com:42paris/minilibx-linux.git $(MLX_PATH); \
		$(MAKE) --silent -C $(MLX_PATH); \
	fi

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@
	
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CC_FLAGS) $(LINK_FLAGS) -I/usr/include -Imlx_linux -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

l: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJ_PATH)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) --silent -C $(LIBFT_PATH) clean; \
	fi
	@if [ -d $(MLX_PATH) ]; then \
		$(MAKE) --silent -C $(MLX_PATH) clean; \
	fi
	

fclean: clean
	@$(RM) $(NAME)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(RM) $(LIBFT_PATH); \
	fi
	@if [ -d $(MLX_PATH) ]; then \
		$(RM) $(MLX_PATH); \
	fi

re: fclean all


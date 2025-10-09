# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 14:49:08 by david-fe          #+#    #+#              #
#    Updated: 2025/10/09 13:40:09 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

#==============================================================================#
#                                  COMPILER AND FLAGS                          #
#==============================================================================#

CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g
LINK_FLAGS	=	-lXext -lX11 -lm

#==============================================================================#
#                                  PATHS       					               #
#==============================================================================#

SRC_PATH		=	src
OBJ_PATH		=	.build
INCLUDE_PATH	=	includes

#==============================================================================#
#                                  LIBFT       					               #
#==============================================================================#

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

#==============================================================================#
#                                  MLX       					               #
#==============================================================================#

MLX_PATH		=	mlx-linux
MLX				=	$(MLX_PATH)/libmlx_Linux.a

#==============================================================================#
#                                  INCLUDES			                           #
#==============================================================================#

INCLUDES    =   -I$(INCLUDE_PATH) -I$(LIBFT_PATH) -I/usr/include -I$(MLX_PATH)

#==============================================================================#
#                                  PROJECT NAME                                #
#==============================================================================#

NAME		=	cub3d

#==============================================================================#
#                                  SOURCE AND OBJECT FILES                     #
#==============================================================================#

SRC_PARSING = $(addprefix parsing/, file_data_extraction.c file_validation.c gnl.c map_extraction_utils.c \
							map_validation.c parsing_cleanup.c parsing_errors.c parsing_errors2.c parsing_utils.c \
							scene_extraction_utils.c t_map_info_setters.c texture_extraction_utils.c)

SRC = $(addprefix $(SRC_PATH)/, main.c inits.c frees.c events.c draw.c color_utils.c calcs.c render.c print.c \
							move.c raycast_dist.c cleanup.c $(SRC_PARSING))

OBJ         =   $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

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
	@echo "$(CYA)Compiling $<$(D)"
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

# Build the cub3d program
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(LINK_FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

l: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Clean object files
clean:
	@if [ -d "$(OBJ_PATH)" ]; \
		then echo "$(RED)[REMOVED OBJECT FILES]$(END)"; \
		else echo "$(YEL)[NO OBJECTS TO CLEAN]$(END)"; \
	fi
	@$(RM) $(OBJ_PATH)
	@if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) --silent -C $(LIBFT_PATH) clean; \
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

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B		= $(shell tput bold)
BLA		= $(shell tput setaf 16)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 46)
BRW		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 27)
PRP		= $(shell tput setaf 57)
CYA		= $(shell tput setaf 51)
WHI		= $(shell tput setaf 15)
GREY	= $(shell tput setaf 8)
ORAN	= $(shell tput setaf 202)
YEL		= $(shell tput setaf 226)
D		= $(shell tput sgr0)
BEL		= $(shell tput bel)
CLR		= $(shell tput el 1)

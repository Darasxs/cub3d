# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 14:17:46 by paprzyby          #+#    #+#              #
#    Updated: 2024/12/05 17:48:21 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME			=	cub3d

SRC				=	main.c \
					check_map_extension.c \
					map_init.c \
					struct_init.c \
					map_validation.c \
					characters_check.c \
					the_game.c \
					player_movement.c \
					raycasting.c \
					cleanup.c

LIBMLX_DIR		=	./MLX42
LIBFT_DIR		=	libft
GNL_DIR			=	get_next_line

OBJ				=	$(SRC:.c=.o)
LIBFT			=	$(LIBFT_DIR)/libft.a
GNL				=	$(GNL_DIR)/get_next_line.a

CC				=	cc

RM				=	rm -f
RMDIR			=	rm -rf

FLAGS			=	-Wall -Wextra -Werror -g
MLX_FLAGS		:=	-L./MLX42/build -lmlx42 -I./MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

HEADERS			:=	-I ./include -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR) -I $(GNL_DIR)

MLX_REPO		=	https://github.com/codam-coding-college/MLX42.git

all:			$(NAME)

mlx:			$(LIBMLX_DIR)/build/stamp

$(LIBMLX_DIR)/build/stamp: $(LIBMLX_DIR)
	@cd $(LIBMLX_DIR) && git pull
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	@make -C $(LIBMLX_DIR)/build -j4
	@touch $@

$(LIBMLX_DIR):
	@if [ ! -d $(LIBMLX_DIR) ]; then \
		git clone $(MLX_REPO) $(LIBMLX_DIR); \
	fi

$(NAME):	mlx $(OBJ) $(LIBFT) $(GNL)
	@echo "------------------------------------------------"
	@printf "$(CLEAR_LINE)$(YELLOW)Compiling files$(NC)\n\n"
	@$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) -o $@ $(LIBFT) $(GNL)
	@if [ ! -d $(NAME) ]; then \
		echo "\n$(GREEN)$(NAME) compiled successfully!$(NC)"; \
		echo "\n"; \
		echo "run with: ./$(NAME)"; \
		echo "------------------------------------------------"; \
	else \
		echo "$(RED)$(NAME) failed to compile$(NC)"; \
	fi

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(GNL):		$(LIBFT)
	@make -C $(GNL_DIR)

clean:
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@echo "$(RED)Removing object files...$(NC)"
	@$(RM) $(OBJ)
	@$(RMDIR) $(LIBMLX_DIR)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@$(RMDIR) $(LIBMLX_DIR)
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re mlx

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m
CLEAR_LINE = \033[2K\r

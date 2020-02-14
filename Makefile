# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 12:42:36 by aszhilki          #+#    #+#              #
#    Updated: 2020/02/14 13:50:24 by aszhilki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c calculate.c scene.c controls.c color.c draw.c keys.c mouse.c
SRC_PATH = ./src/
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

MLX_PATH = ./minilibx/
MLX_LIB = ./minilibx/libmlx.a
MLX_LNK = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

LFT_PATH = ./libft/
LFT_LIB = ./libft/libft.a
LFT_LNK = -L ./libft -lft

all: $(NAME)

$(LFT_LIB):
	@echo "(-᷅_-᷄๑) in process\n"
	@make -C $(LFT_PATH)
	@echo "."

$(MLX_LIB):
	@echo "."
	@make -C $(MLX_PATH)
	@echo "."

$(NAME): $(LFT_LIB) $(MLX_LIB)
	@echo "."
	@gcc -o $(NAME) $(SRC) $(LFT_LNK) $(MLX_LNK) $(FLAGS)
	@echo "."
	@echo "success (•̀ᴗ•́)و"
	@echo "________________________________________________"
	@echo "Choose julia, mandelbrot, tricorn or burningship"
	@echo "________________________________________________\n"

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LFT_PATH) fclean
	@echo "all clean! ɿ(｡･ɜ･)ɾ"

re: fclean all

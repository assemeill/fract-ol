# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 12:42:36 by aszhilki          #+#    #+#              #
#    Updated: 2020/01/30 16:03:42 by aszhilki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c calculate.c scene.c controls.c color.c
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

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(NAME): $(LFT_LIB) $(MLX_LIB)
	@gcc -o $(NAME) $(SRC) $(LFT_LNK) $(MLX_LNK) $(FLAGS)
	@echo "success (•̀ᴗ•́)و ̑̑"

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LFT_PATH) fclean
	@echo "all clean! ɿ(｡･ɜ･)ɾ"

re: fclean all

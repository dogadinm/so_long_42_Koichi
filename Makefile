NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLXFLAGS	=	-L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
MINILIBX_PATH	=	./minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SRC = main.c map_checks.c map_info.c map_size.c move.c passability_check.c utilities.c

OBJ = $(SRC:%.c=%.o)

all: ${NAME}

${NAME}: $(OBJ)
	$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
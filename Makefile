#***** Name *****#

NAME			=		cub3D

#***** Sources / Objs *****#

SRC				=		main.c utils_free.c test_ray.c\
						$(addprefix ./init/, init_base.c init_map.c init_asset.c cmp_asset.c utils.c)\
						$(addprefix ./error/, error_args.c) \
						$(addprefix ./asset_cardinal/, asset_is_valid.c check_path_is_valid.c) \
						$(addprefix ./asset_color/, asset_color.c color_nbr.c asset_color_utils.c)\
						$(addprefix ./win_minimap/, init_minimap.c mini_map.c win.c)\
						$(addprefix ./player/, player.c move_p.c)\
						./src/ft_mlx/img.c	./src/assets.c

OBJS			=		$(SRC:.c=.o)

#***** Libft *****#

LIBFT			=		./libft/libft.a
MLIBFT			=		$(MAKE) -C libft
MLXLIB			=		./src_mlx/mlx/libmlx.a
DIR_MLX			=		./src_mlx/mlx
LIBFT_MLX		=		$(MAKE) -C libft && $(MAKE) -C ./src_mlx/mlx

#***** Couleurs *****#

GREEN			=		\033[1;32m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m
BG_G			=		\033[42m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_G)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Logo *****#

MSHELL			=		echo "$(GREEN)\t  ______   __    __  _______   ________   ______   _______ \n\
									\t /      \ /  |  /  |/       \ /        | /      \ /       \  \n\
									\t/888888  |88 |  88 |8888888  |88888888/ /888888  |8888888  |\n\
									\t88 |  88/ 88 |  88 |88 |__88 |88 |__    88 ___88 |88 |  88 |\n\
									\t88 |      88 |  88 |88    88< 88    |     /   88< 88 |  88 |\n\
									\t88 |   __ 88 |  88 |8888888  |88888/     _88888  |88 |  88 |\n\
									\t88 \__/  |88 \__88 |88 |__88 |88 |_____ /  \__88 |88 |__88 |\n\
									\t88    88/ 88    88/ 88    88/ 88       |88    88/ 88    88/ \n\
									\t 888888/   888888/  8888888/  88888888/  888888/  8888888/  $(ENDCOLOR)\n"


#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer
RM				=		rm -f
LIBS			= 		-Lsrc_mlx/mlx -lmlx -framework OpenGL -framework AppKit
HEADER			=		-I./includes -I./libft/libft.h -I./src_mlx/mlx/mlx.h

ifeq ($(shell uname), Linux)
MLXLIB			=		./src_mlx/mlx-linux/libmlx.a
DIR_MLX			=		./src_mlx/mlx-linux/
LIBFT_MLX		=		$(MAKE) -C libft && $(MAKE) -C ./src_mlx/mlx-linux
LIBS			=		-L ./src_mlx/mlx-linux/ -lmlx -Ilmlx -lXext -lX11 -lm
HEADER			=		-I./includes -I./libft/ -I./src_mlx/mlx-linux/
endif

#***** Compilation *****#

all : lib start logo $(NAME)



lib:
			@$(LIBFT_MLX) all
			@$(END_COMP_LIB)

start:
			@$(START)

logo :
			@$(MSHELL)


%.o:		%.c cube3d.h ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -g $(HEADER) -c $< -o $@
			@$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${LIBS} ${HEADER} -o ${NAME}
			@$(END_COMP)

l :			${OBJS}
			@${LIBFT_MLX} all
			${CC} ${L} ${OBJS} ${LIBFT} ${LIBS} ${HEADER} -o ${NAME}
			@$(END_COMP)


#***** Clean *****#

clean:
			@$(S_OBJS)
			${RM} ${OBJS}
			cd ${DIR_MLX} make clean
			${MLIBFT} clean

fclean:		clean
			@$(S_NAME)
			${RM} ${NAME}
			cd ${DIR_MLX} make fclean
			${MLIBFT} fclean

re:			fclean all

docker:
	docker build -t arch .
	docker run -it --name archnm -v $(current_dir):/ft_nm arch

docker_start:
	docker start -i archnm

docker_run:
	docker exec -it archnm /bin/zsh

prune:
	docker system prune -a --volumes


.PHONY:		all clean fclean docker docker_start docker_run prune
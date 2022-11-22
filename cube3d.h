#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"

# if defined(__APPLE__) && defined(__MACH__)
#  include "./src_mlx/mlx/mlx.h"
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  include "./src_mlx/mlx-linux/mlx.h"
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif



typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}		t_mlx;
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}		t_player;

typedef struct s_map
{
	void		*img;
	char		**tab_map;
	t_mlx		*mlx;
	t_player	*player;
}		t_map;

/////////// INIT ///////////
void	init(t_map *map);
void	init_struct_map(t_map *map);
void	init_player(t_map *map);
void	callocmap(t_map *map, int haut);

////////// ERROR //////////
int		erreur_args(int argc, char **argv);
int		check_arg(char *c);

////////// INIT MAP //////////
void	compt_map_haut(char *args, t_map *map);
void	compt_map(char *args, t_map *map, int haut);
void	init_tab_map(char *args, t_map *map, int *larg, int haut);
int		map_is_close(t_map *map);
int		check_wall(t_map *map, int i, int j);

////////// FREE //////////
int		free_main(t_map *map);

#endif

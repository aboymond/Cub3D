#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"

# define RED 0x00FF0000
# define YEL 0x00FFFF00
# define GREEN 0x003AFF00
# define GRE 0x00808080
# define BLU 0x00002EFF
# define WHI 0x00FFFFFF

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
	char	cardi;
}		t_player;

typedef struct s_asset
{
	char		**asset_NSWE;
	char		**asset_color;
	int			cmpt_asset;
	int			cmpt_asset_tab;
	int			int_NSWE;
	int			nbr_NSWE;
	int			int_color;
	int			nbr_color;
}		t_asset;
typedef struct s_map
{
	char		**tab_map;
	int			len_map;
	int			x;
	int			y;
}		t_map;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

// typedef	struct s_img
// {
// 	void	*mlx_img;
// 	int		width;
// 	int		height;
// } t_img;

typedef struct s_scene
{
	t_map		map;
	t_asset		asset;
	t_player	player;
	t_img		img;
	t_mlx		mlx;
} t_scene;

/*
manage_assets(t_struct *asset)
{
	asset.int_color = 0;
}
t_map *map;
map.asset.int_color = 1;
manage_assets(&map->assets)
//int_color == 0


typedef struct	s_map
{
	char **data;
	int	height;
	int widht;
} t_map;
*/


/////////// INIT ///////////
void	init(t_scene *scene);
void	init_struct_map(t_scene *scene);
void	init_player(t_scene *scene);
void	init_asset_var(t_scene *scene);
int		init_asset_tab(t_scene *scene, char *line);
int		init_asset(char *args, t_scene *scene);
int		check_asset(t_scene *scene, char *line);
void	callocmap(t_scene *scene, int haut);
int		compt_asset(char *args, t_scene *scene);
int		nb_of_asset(char *line, t_asset *asset);
int		malloc_asset(t_asset *asset);

////////// INIT MAP //////////
int		compt_map(char *args, t_scene *scene);
void	init_tab_map(char *args, t_scene *scene, int haut);
int		map_is_close(t_scene *scene);
int		check_wall(char **tab, int i, int j);

////////// ERROR //////////
int		erreur_args(int argc, char **argv);
int		check_arg(char *c);
int		p_error(char *error);

////////// ASSET //////////
int 	valid_p_cardinal_name(char *str, int i);
int		asset_p_cardinal(t_asset *asset);
int 	asset_color(t_asset *asset);
int		name_is_valid(char *str, int i);
int		asset_is_valid(t_asset *asset);
int		valid_color_name(char *str, int i);
int		value_color(t_asset *asset);
int 	valid_color(char *str);
int		color_into_d_tab(char *str);
int		is_a_digit(char **trim_str);
int		color_rvb(char **trim_str);
int 	count_nbr_color(char **tab_color);








////////// FREE //////////
int		free_main(t_scene *scene);
void	free_d_tab(char **str);

///////// UTILS ///////////
int		comp_size_len(t_scene *scene, char *line);
int		cpy_map_to_tab(t_scene *scene, char *line, int i);
int		utils_c_w(char c, int car);

///////// TEST ///////////
int		open_win(t_scene *scene);
int		mxl_pixel_put(t_scene *scene, int x, int y, int color);
int		mini_map_pixel(t_scene *scene, int x, int y, int floor, int size);
int		mini_map_init(t_scene *scene);
int		mini_map_pixel_border(t_scene *scene, int x, int y, int size);

#endif

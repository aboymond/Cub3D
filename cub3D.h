/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:39:04 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 17:50:41 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"

# define RED 0x00FF0000
# define YEL 0x00FFFF00
# define GREEN 0x003AFF00
# define GRE 0x00808080
# define BLU 0x00002EFF
# define WHI 0x00FFFFFF
# define WIN_X 1920
# define WIN_Y 1080
# define SPD 0.1
# define SPDR 1
# define FOV 0.90

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
#  define ESC					65307
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define SHIFT					6530
# endif

typedef struct s_tex
{
	void	*ptr;
	void	*data;
	int		*tex_data;
	float	step;
	float	texpos;
	int		h;
	int		w;
	int		x;
	int		y;
	char	*addr;
	int		color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_tex;

typedef struct s_img {
	void	*img;
	void	*map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}		t_mlx;

typedef struct s_vec2
{
	float	x;
	float	y;
}		t_vec2;

typedef struct s_player
{
	int			x_f;
	int			y_f;
	int			start;
	int			end;
	int			lineh;
	char		color_card;
	int			stepx;
	int			stepy;
	int			side;
	int			texx;
	float		rposx;
	float		rposy;
	float		wallx;
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		raydir;
	t_vec2		plane;
	t_vec2		map;
	t_vec2		old_plane;
	t_vec2		sdist;
	t_vec2		old_dir;
	t_vec2		delta;
	t_vec2		cam;
	float		perpwdist;
	char		cardi;
}		t_player;

typedef struct s_asset
{
	char		**asset_nswe;
	char		**tab_path;
	char		**tab_color;
	int			*floor_color;
	int			*ceiling_color;
	char		**asset_color;
	int			floor_hex;
	int			ceil_hex;
	int			cmpt_asset;
	int			cmpt_asset_tab;
	int			int_nswe;
	int			nbr_nswe;
	int			int_color;
	int			nbr_color;

	t_img		*tex_s;
	t_img		*tex_n;
	t_img		*tex_w;
	t_img		*tex_e;
}		t_asset;
typedef struct s_map
{
	char		**tab_map;
	int			len_map;
	int			map_size;
	int			x;
	int			y;
}		t_map;

typedef struct s_scene
{
	t_map		map;
	t_asset		asset;
	t_player	player;
	t_img		*img;
	t_mlx		mlx;

	t_tex		ptr;
}	t_scene;

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
int		init_asset_2(char *trimmed, t_scene *scene, char *tmp, int fd);

////////// INIT MAP //////////
void	compt_map(char *args, t_scene *scene);
void	init_tab_map(char *args, t_scene *scene);
int		map_is_close(t_scene *scene);
int		check_wall(char **tab, int i, int j);
void	compt_map_2(t_scene *scene, int haut, char *args);

////////// ERROR //////////
int		erreur_args(int argc, char **argv);
int		check_arg(char *c);
int		p_error(char *error);

////////// ASSET //////////
int		valid_p_cardinal_name(char *str, int i);
int		asset_p_cardinal(t_asset *asset);
int		asset_color(t_asset *asset);
int		name_is_valid(char *str, int i);
int		asset_is_valid(t_asset *asset);
int		valid_color_name(char *str, int i);
int		value_color(t_asset *asset);
int		valid_color(char *str);
int		color_into_d_tab(char *str);
int		is_a_digit(char **trim_str);
int		color_rvb(char **trim_str);
int		count_nbr_color(char **tab_color);
int		path_not_valid(t_asset *asset);
void	delete_p_cardinal(char **tab_path, t_asset *asset);
int		two_same_path(char **path);
void	convert_tab_char_to_int(char *floor, char *ceiling, t_asset *asset);
void	create_tab_integer_ceiling(char *str, t_asset *asset);
void	create_tab_integer_floor(char *str, t_asset *asset);
int		trim_space_in_path(char	**path);
int		valid_p_cardinal_name2(char *str, int i);

////////// PLAYER /////////
int		init_pos_player(t_scene *scene, int y, int x);
int		print_player(t_scene *scene, int x, int y);
int		key_move(int keycode, t_scene *scene);
int		search_player(t_scene *scene);
int		key_right(t_player *player);
int		key_left(t_player *player);
int		key_down(t_scene *scene, t_player *player);
int		key_up(t_scene *scene, t_player *player);
int		l_right(t_scene *scene, t_player *player);
int		l_left(t_scene *scene, t_player *player);
int		key_esc(int keycode, t_scene *scene);
int		key_move2(int keycode, t_scene *scene);
int		init_pos_player_map(t_scene *scene, int y, int x, int size);

////////// WIN_MINIMAP ///
int		mini_map_init(t_scene *scene);
int		mxl_texture_put(t_scene *scene, int x, int y, int color);
int		open_win(t_scene *scene);
int		mxl_pixel_put(t_scene *scene, int x, int y, int color);
int		mini_map_pixel(t_scene *scene, int x, int y, int floor);
int		mini_map_pixel_border(t_scene *scene, int x, int y, int size);
int		mlx_open_win(t_scene *scene);
int		mlx_open_win_map(t_scene *scene);
int		open_win_map(t_scene *scene);
int		search_player(t_scene *scene);

////////// FREE //////////
int		free_main(t_scene *scene);
void	free_tab(t_scene *scene);
void	free_d_tab(char **str);
void	tab_free(char *str);

///////// UTILS ///////////
int		comp_size_len(t_scene *scene, char *line);
int		cpy_map_to_tab(t_scene *scene, char *line, int i);
int		utils_c_w(char c, int car);
int		map_is_close_2(t_scene *scene, int j, int i, int comp);

//////////TEST //////
int		init_ray(t_scene *scene);
int		init_miniray(t_scene *scene);
int		draw_wall(t_scene *scene, int x);
int		init_height_wall(t_scene *scene);
int		init_color_wall(t_scene *scene);
int		init_sdist(t_scene *scene);
void	init_sdist_2(t_scene *scene);
void	init_perpwall(t_scene *scene);
int		init_delta(t_scene *scene);
int		dda_hit(t_scene *scene);
int		init_ray_dir(t_scene *scene, int x);
int		texture(t_scene *scene);
int		convert_rvb_to_hexa(t_scene *scene);
void	tex_to_pixel(t_img *tex, t_scene *scene);
int		load_tex(t_scene *scene);
int		init_tex_width(t_scene *scene);
int		init_tex_height(t_scene *scene);
t_tex	*new_texture(t_scene *scene, char *path);

int		wall(t_scene *scene);

t_img	*ftmlx_new_xpm_img(void *mlx, char *file);
void	ftmlx_free_img(void *mlx, t_img *img);
t_img	*ftmlx_new_img(void *mlx, int width, int height);

//assets
void	init_assets(t_asset *assets);
int		load_assets(void *mlx, t_asset *assets);
void	free_assets(void *mlx, t_asset *assets);
int		ft_close(void);

#endif

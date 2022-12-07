#include "cub3D.h"

int	key_move(int keycode, t_scene *scene)
{
	// (void)scene;
	float	x;
	float	y;

	y = scene->player.pos.y / scene->map.map_size;
	x = scene->player.pos.x / scene->map.map_size;
	scene->player.old.y = scene->player.pos.y;
	// printf("pos_old_x 0 = %f, pos_old_y = %f\n", scene->player.pos.x / scene->map.map_size, scene->player.pos.y / scene->map.map_size);
	// printf("key = %d\n", keycode);
	// printf("pos_x = %f, pos_y = %f\n", scene->player.pos.x / scene->map.map_size, scene->player.pos.y / scene->map.map_size);
	if (keycode == RIGHT_KEY)
	{
		scene->player.old.x = scene->player.pos.x;
		scene->player.pos.x++;
		printf("pos_old_x 1 = %f, pos = %f\n", scene->player.old.x / scene->map.map_size, scene->player.pos.x / scene->map.map_size);
		if (scene->map.tab_map[(int)y][(int)x] == '1')
		{
			scene->player.pos.x = scene->player.old.x;
			return(0);
		}
		else
		{
			scene->player.old.x = scene->player.pos.x;
			scene->player.pos.x++;
			printf("pos_old_x 2 = %f, pos = %f\n", scene->player.old.x / scene->map.map_size, scene->player.pos.x / scene->map.map_size);
			scene->player.old.x--;
			//del_old_print_player(scene, scene->player.old.x - 1, scene->player.old.y);
			//mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
		}
	}
	if (keycode == LEFT_KEY)
	{
		scene->player.pos.x--;
		if (scene->map.tab_map[(int)y][(int)x] == '1')
		{
			scene->player.pos.x = scene->player.old.x;
			return(0);
		}
		else
		{
			printf("key 53\n");
			// exit(0);
			//print_player(scene, scene->player.pos.x, scene->player.pos.y);
			scene->player.pos.x--;
			scene->player.old.x++;
			//del_old_print_player(scene, scene->player.old.x + 1, scene->player.old.y);
			//mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);

		}
	}
// 	if (keycode == UP_KEY)
// 	{
// 		if (scene->map.tab_map[y][x] == '1')
// 			return(0);
// 		printf("key 53\n");
// 		// exit(0);
// 		scene->player.pos.y--;
// 		print_player(scene, scene->player.pos.x, scene->player.pos.y);
// 		scene->player.old.y++;
// 		del_old_print_player(scene, scene->player.old.x, scene->player.old.y + 1);
// 		mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
// 	}
// 	if (keycode == DOWN_KEY)
// 	{
// 		if (scene->map.tab_map[y][x] == '1')
// 			return(0);
// 		printf("key 53\n");
// 		// exit(0);
// 		scene->player.pos.y++;
// 		print_player(scene, scene->player.pos.x, scene->player.pos.y);
// 		scene->player.old.y--;
// 		del_old_print_player(scene, scene->player.old.x, scene->player.old.y - 1);
// 		mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
// 	}
	return (0);
}
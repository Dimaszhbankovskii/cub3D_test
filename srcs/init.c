#include "../includes/executor.h"

static void init_texture(t_data *data, void *mlx, char *filename)
{
	int		width;
	int		height;
	
	width = 0;
	height = 0;
	data->img = mlx_xpm_file_to_image(mlx, filename,  &width, &height);
	if (!data->img)
	{
		//error
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
								&data->line_length, &data->endian);
}

static void	init_player(t_game *game)
{
	game->player.x = 5 * game->texture_size + game->texture_size / 2;	// координата x
	game->player.y = 5 * game->texture_size + game->texture_size / 2;	// координата y
	game->player.pov = 180;			// ???
	game->player.step_length = 20;	// шаг передвижения ???
}

void	init_game(t_game *game)
{
	game->map = parse_map();	// парсинг карты, в структуру
	game->mlx = mlx_init();		// инициализация mlx
	game->texture_size = 64;	// размер текстур
	game->plane_width= 640;		// ширина окна
	game->plane_height = 400;	// высота окна
	game->fov = 60;				// определение ???
	game->win = mlx_new_window(game->mlx, game->plane_width, game->plane_height, "cub3D"); // инициализация окна
	game->dist_to_plane = game->plane_width / 2.0 / tan(game->fov/2.0 * PI_TO_RAD); // определение ???
	game->delta_angle = game->fov / game->plane_width;	// определение ???
	init_texture(&game->wall, game->mlx, "wall.xpm");
	init_player(game);			// инициализация стурктуры player
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:09:36 by rmoujan           #+#    #+#             */
/*   Updated: 2022/01/07 15:31:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// //for esc key
int	close_esc(int keycode, t_long *game)
{
	//printf("key code is %d", keycode);
	//53 is the keycode of esc key
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else
	{
		return (1);
	}
}
//for the crose
int close_crose(t_long *game)
{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
}

void exit_window(void)
{
	//mlx_destroy_window(game->mlx, game->win);
	write(1, "Error\n", 6);
	write(1, "INVALID CARD...BE CAREFUL !!! ",30);
	exit(0);
}
void up(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x - 1][game->y] == '0')
	{
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x + 1)*40);
	}
}
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

int	key_hook(int keycode, t_long *game)
{
	if (keycode == 13)
	{
		up(game);
	}
	printf("Hello from key_hook is %d!\n", keycode);
	return (0);
}


int	main(int argc, char *argv[])
{

	t_long	game;
	//char	**tab = NULL;
	int	i;
	int j;


	i = 0;
	j = 0;
	//full the array with tha map :
	import_map(&game.tab, argv[argc - 1]);
	//starting checking the map ::
	//check is the map contain just 1 0 P E C
	check_map_charachters(game.tab);
	//printf("HALLLO WORLD Before\n");
	//check is the map rectangular :
	is_rectangular(game.tab);
	//printf("AFTER RECTU \n");
	//check is the map surrounded by walls(1) :
	is_surrounded(game.tab);
	//printf("AFTER surrounded \n");
	//check is the map contain at least 1 E, 1 C, and 1 P :
	//printf("*** BEFORE check map ECP ***\n");
	check_map_ecp(game.tab);
	//printf("*** AFTER check map ECP ***\n");
	//printf("HALLLO WORLD AFTER \n");

	//starting the game :
	game.mlx = mlx_init();
	//printf("value of l is %d nad value of c is %d \n", l, c);
	line_column(game.tab, &i, &j);
	//printf("value of l is %d nad value of c is %d \n", l, c);
	game.win = mlx_new_window(game.mlx, 60*j, 40*i, "./so_long");
//	get_index_player(game);
	//for esc key :
	mlx_hook(game.win, 2, 0, close_esc, &game);
	//for the crose :
	mlx_hook(game.win, 17, 0, close_crose, &game);
	creating_window(game.tab, game);
	//starting moving the main character :
	//test W up :
	mlx_hook(game.win, 2, 0, key_hook, &game);
	//get_index_player(&game);
	//printf("output from main x == %d and y == %d", game.x, game.y);
	
	//mlx_key_hook(game.win, key_hook, &game);


	mlx_loop(game.mlx);
}
// W :up
// A :left
// S :down
// D :right
//int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
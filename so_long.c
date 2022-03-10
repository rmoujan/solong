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
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

int	main(int argc, char *argv[])
{

	t_long	game;
	char	**tab = NULL;
	int	i;
	int j;


	i = 0;
	j = 0;
	//full the array with tha map :
	import_map(&tab, argv[argc - 1]);
	//starting checking the map ::
	//check is the map contain just 1 0 P E C
	check_map_charachters(tab);
	//printf("HALLLO WORLD Before\n");
	//check is the map rectangular :
	is_rectangular(tab);
	//printf("AFTER RECTU \n");
	//check is the map surrounded by walls(1) :
	is_surrounded(tab);
	//printf("AFTER surrounded \n");
	//check is the map contain at least 1 E, 1 C, and 1 P :
	//printf("*** BEFORE check map ECP ***\n");
	check_map_ecp(tab);
	//printf("*** AFTER check map ECP ***\n");
	//printf("HALLLO WORLD AFTER \n");

	//starting the game :
	game.mlx = mlx_init();
	//printf("value of l is %d nad value of c is %d \n", l, c);
	line_column(tab, &i, &j);
	//printf("value of l is %d nad value of c is %d \n", l, c);
	game.win = mlx_new_window(game.mlx, 60*j, 40*i, "./so_long");
	//for esc key
	mlx_hook(game.win, 2, 0, close_esc, &game);
	//for the crose
	mlx_hook(game.win, 17, 0, close_crose, &game);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1')
			{
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/w.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			//game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/wall.xpm", &game.img.width, &game.img.height);
			//mlx_put_image_to_window(game.mlx, game.win, game.img.img, 120,20);
			}
			else if (tab[i][j] == '0')
			{
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			else if (tab[i][j] == 'C')
			{
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/coll.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			
			else if (tab[i][j] == 'E') 
			{
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/door.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			else if (tab[i][j] == 'P') 
			{
			//game.img.img = mlx_new_image(game.mlx, 10, 10);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/mira.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			j++;
		}
		i++;
	}


	mlx_loop(game.mlx);
}

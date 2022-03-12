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

int	close_esc(int keycode, t_long *game)
{
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

int	close_crose(t_long *game)
{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
}

void	exit_window(void)
{
	write(1, "Error\n", 6);
	write(1, "INVALID CARD...BE CAREFUL !!! ",30);
	exit(0);
}

//for moving the main character
int	key_hook(int keycode, t_long *game)
{
	if (keycode == 13)
		up(game);
	else if (keycode == 0)
		left(game);
	else if (keycode == 1)
		down(game);
	else if (keycode == 2)
		right(game);
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{

	t_long	game;
	int		i;
	int		j;

	game.move = 0;
	game.collect = 0;
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
	numbers_collectibles(&game);
	//printf("numbers of collectibles is %d \n", game.collect);
//	get_index_player(game);
	//for esc key :
	mlx_hook(game.win, 2, 0, close_esc, &game);
	//for the crose :
	mlx_hook(game.win, 17, 0, close_crose, &game);
	creating_window(game.tab, game);
	//starting moving the main character (this func that cutch evary event in map) :
	mlx_hook(game.win, 2, 0, key_hook, &game);
	//numbers_collectibles(&game);
	//printf("numbers of collectibles is %d \n", game.collect);
	mlx_loop(game.mlx);
}
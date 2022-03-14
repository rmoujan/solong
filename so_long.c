/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:09:36 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/14 10:21:11 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// //for esc key :
// int	close_esc(int keycode, t_long *game)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else
// 	{
// 		return (1);
// 	}
// }

//for the crose :
int	close_crose(t_long *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	exit_window(void)
{
	write(1, "Error\n", 6);
	write(1, "INVALID CARD...BE CAREFUL !!! ", 30);
	exit(0);
}

//for pressing a key and moving the main character
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
	if (argc == 1)
		exit(0);
	import_map(&game.tab, argv[argc - 1]);
	check_map_charachters(game.tab);
	is_rectangular(game.tab);
	is_surrounded(game.tab);
	check_map_ecp(game.tab);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(0);
	line_column(game.tab, &i, &j);
	game.win = mlx_new_window(game.mlx, 60 * j, 40 * i, "./so_long");
	if (game.win == NULL)
		exit(0);
	numbers_collectibles(&game);
	//mlx_hook(game.win, 2, 0, close_esc, &game);
	mlx_hook(game.win, 17, 0, close_crose, &game);
	creating_window(game.tab, game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_loop(game.mlx);
}

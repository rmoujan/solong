/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:09:36 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/16 10:22:46 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	exit(1);
}

//for pressing a key and moving the main character
int	key_hook(int keycode, t_long *game)
{
	if (keycode == 13 || keycode == 126)
		up(game);
	else if (keycode == 0 || keycode == 123)
		left(game);
	else if (keycode == 1 || keycode == 125)
		down(game);
	else if (keycode == 2 || keycode == 124)
		right(game);
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	all_checks(char **tab, char *str)
{
	check_map_charachters(tab);
	is_rectangular(tab);
	is_surrounded(tab);
	check_map_ecp(tab);
	check_argv(str);
}

int	main(int argc, char *argv[])
{
	t_long	game;
	int		i;
	int		j;

	ft_initialize(&game.move, &game.collect, &game.eat, &game.left);
	game.right = 1;
	i = 0;
	j = 0;
	if (argc == 1)
		exit(1);
	import_map(&game.tab, argv[argc - 1]);
	all_checks(game.tab, argv[argc - 1]);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(1);
	line_column(game.tab, &i, &j);
	game.win = mlx_new_window(game.mlx, 60 * j, 40 * i, "./so_long");
	if (game.win == NULL)
		exit(1);
	numbers_collectibles(&game);
	mlx_hook(game.win, 17, 0, close_crose, &game);
	creating_window(game.tab, game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

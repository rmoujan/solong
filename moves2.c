/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:57:49 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/15 16:34:50 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x + 1][game->y] == '0')
	{
		game->move++;
		if (game->right == 1 && game->left == 0)
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pla.xpm",
					&game->img.width, &game->img.height);
		else
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/lpla.xpm",
					&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y) * 60 + 10, (game->x + 1) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.img, game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x + 1][game->y] = 'P';
		moves(game);
	}
	down_chunks(game);
}

void	down_chunks(t_long *game)
{
	if (game->tab[game->x + 1][game->y] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x + 1) * 40);
		if (game->right == 1 && game->left == 0)
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pla.xpm",
					&game->img.width, &game->img.height);
		else
			game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/lpla.xpm",
					&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y) * 60 + 10, (game->x + 1) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x + 1][game->y] = 'P';
		moves(game);
	}
	else if (game->tab[game->x + 1][game->y] == 'E')
	{
		printf("game-->eat == %d\n", game->eat);
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

void	right(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x][game->y + 1] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pla.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y + 1) * 60 + 10, (game->x) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y + 1] = 'P';
		moves(game);
		game->right = 1;
		game->left = 0;
	}
	right_chunks(game);

}

void	right_chunks(t_long *game)
{
	if (game->tab[game->x][game->y + 1] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y + 1) * 60, (game->x) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pla.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y + 1) * 60 + 10, (game->x) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y + 1] = 'P';
		moves(game);
		game->right = 1;
		game->left = 0;
	}
	else if (game->tab[game->x][game->y + 1] == 'E')
	{
		printf("game-->eat == %d\n", game->eat);
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

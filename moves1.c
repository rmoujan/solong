/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:05:17 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/14 11:46:42 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//for moving the main charcter up
void up(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x - 1][game->y] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x - 1)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x - 1][game->y] = 'P';
		moves(game);
	}
	else if (game->tab[game->x - 1][game->y] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x - 1)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x - 1][game->y] = 'P';
		moves(game);
	}
	else if (game->tab[game->x - 1][game->y] == 'E')
	{
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

void left(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x][game->y - 1] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y - 1)*60,(game->x)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y - 1] = 'P';
		moves(game);
	}
	else if (game->tab[game->x][game->y - 1] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y - 1)*60,(game->x)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y - 1] = 'P';
		moves(game);
	}
	else if (game->tab[game->x][game->y - 1] == 'E')
	{
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

void down(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x + 1][game->y] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y)*60,(game->x + 1)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x + 1][game->y] = 'P';
		moves(game);
	}

	else if (game->tab[game->x + 1][game->y] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y)*60,(game->x + 1)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x + 1][game->y] = 'P';
		moves(game);
	}
	else if (game->tab[game->x + 1][game->y] == 'E')
	{
		//printf("inside E\n");
		//printf("GAME->EAT == %d AND GAME->COOLECT == %d \n",game->eat, game->collect);
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

void right(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x][game->y + 1] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y + 1)*60,(game->x)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y + 1] = 'P';
		moves(game);
	}
	else if (game->tab[game->x][game->y + 1] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/mira.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, (game->y + 1)*60,(game->x)*40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", &game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, game->y*60,(game->x)*40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y + 1] = 'P';
		moves(game);
	}
	else if (game->tab[game->x][game->y + 1] == 'E')
	{
		if (game->eat == game->collect)
		{
			write(1, "Game is Over ... your are winner \n", 34);
			exit(0);
		}
	}
}

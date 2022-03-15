/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:05:17 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/15 08:41:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//for moving the main charcter up
void	up(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x - 1][game->y] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/p.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x - 1) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x - 1][game->y] = 'P';
		moves(game);
	}
	up_chunks(game);
}

void	up_chunks(t_long *game)
{
	if (game->tab[game->x - 1][game->y] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/p.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x - 1) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
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

void	left(t_long *game)
{
	get_index_player(game);
	if (game->tab[game->x][game->y - 1] == '0')
	{
		game->move++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pl.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y - 1) * 60, (game->x) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
		game->tab[game->x][game->y] = '0';
		game->tab[game->x][game->y - 1] = 'P';
		moves(game);
	}
	left_chunks(game);
}

void	left_chunks(t_long *game)
{
	if (game->tab[game->x][game->y - 1] == 'C')
	{
		game->move++;
		game->eat++;
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pl.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			(game->y - 1) * 60, (game->x) * 40);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/s.xpm",
				&game->img.width, &game->img.height);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img,
			game->y * 60, (game->x) * 40);
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

int	numbers_lines(char *ptr)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(ptr, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:31:10 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/14 16:54:23 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creating_window(char **tab, t_long game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1')
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/w.xpm",
						&game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img,
						j * 60, i * 40);
			}
			chunks1(tab[i][j], i, j, game);
			chunks2(tab[i][j], i, j, game);
			j++;
		}
		i++;
	}
}

void	chunks1(char c, int i, int j, t_long game)
{
	if (c == '0')
	{
		game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/s.xpm",
				&game.img.width, &game.img.height);
		mlx_put_image_to_window(game.mlx, game.win,
				game.img.img, j * 60, i * 40);
	}
	else if (c == 'C')
	{
		game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/c.xpm",
				&game.img.width, &game.img.height);
		mlx_put_image_to_window(game.mlx, game.win,
				game.img.img, j * 60, i * 40);
	}	
}

void	chunks2(char c, int i, int j, t_long game)
{
	if (c == 'E')
	{
		game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/d.xpm",
				&game.img.width, &game.img.height);
		mlx_put_image_to_window(game.mlx, game.win,
				game.img.img, j * 60, i * 40);
	}
	else if (c == 'P')
	{
		game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/p.xpm",
				&game.img.width, &game.img.height);
		mlx_put_image_to_window(game.mlx, game.win,
				game.img.img, j * 60, i * 40);
	}
}

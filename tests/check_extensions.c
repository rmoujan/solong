/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:41:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/16 10:22:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*ber;

	ber = "reb.";
	i = ft_strlen(str);
	k = 0;
	j = 0;
	i--;
	while (k < 4)
	{
		if (str[i] == ber[j])
		{
			i--;
			j++;
		}
		else
			exit_window();
		k++;
	}
}

void	ft_initialize(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	ft_final(int a, int b)
{
	if (a == b)
	{
		write(1, "Game is Over ... your are winner \n", 34);
		exit(0);
	}
}

void	up_chunks2(t_long *game)
{
	if (game->right == 1 && game->left == 0)
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/pla.xpm",
				&game->img.width, &game->img.height);
	else
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/lp.xpm",
				&game->img.width, &game->img.height);
}

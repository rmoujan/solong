/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:53:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/12 16:43:55 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_index_player(t_long *game)
{
	int	i;
	int j;
	int f;

	i = 0;
	j = 0;
	f = 0;
	while (game->tab[i] != '\0')
	{
		j = 0;
		while (game->tab[i][j] != '\0')
		{
			if (game->tab[i][j] == 'P')
			{
				f++;
				break;
			}
			j++;
		}
		if (f != 0)
			break;
		i++;
	}
	game->x = i;
	game->y = j;
//	printf("output from function i == %d and j == %d \n", game->x, game->y);
}

void output_map(t_long *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	printf("numbres of move is %d \n", game->move);
	while (game->tab[i] != '\0')
	{
		j = 0;
		while (game->tab[i][j] != '\0')
		{
			printf("%c ", game->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
void moves(t_long *game)
{
	printf("moves %d\n", game->move);
	printf("collect eating %d\n", game->eat);
//	write(1, &game->move, 1);

}

void numbers_collectibles(t_long *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (game->tab[i] != '\0')
	{
		j = 0;
		while (game->tab[i][j] != '\0')
		{
			if (game->tab[i][j] == 'C')
			{
				game->collect++;
			}
			j++;
		}
		i++;
	}
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:09:36 by rmoujan           #+#    #+#             */
/*   Updated: 2022/01/07 15:31:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct map
{
	char **map;
	int column;
	int line;
}t_map;

int main()
{
	//cela vs permet de crier une connexion au serveur
	void *mlx_ptr;
	void *win;

	mlx_ptr = mlx_init();
	if (mlx_ptr)
	{
		win = mlx_new_window(mlx_ptr, 400, 400, "./so_long");
		mlx_loop(mlx_ptr);
	}
	return (0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:41:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/15 16:44:17 by rmoujan          ###   ########.fr       */
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

void	ft_initialize(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

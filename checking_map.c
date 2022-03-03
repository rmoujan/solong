/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:13:38 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/03 11:13:48 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char a)
{
	if (a == 'C' || a == 'P' || a == 'E' || a == '1' || a == '0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
//check is the map rectangular :
void is_rectangular(char **tab)
{
	int	j;
	int	len;
	size_t	total;

	j = 0;
	len  = 0;
	while (tab[j])
	{
		len = len + ft_strlen(tab[j]);
		j++;
	}
	total =  len / j;
	j = 0;
	while (tab[j])
	{
		if (total != ft_strlen(tab[j]))
			exit_window();
		j++;
	}
}

//strchr :
int	ft_search(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}
//check is the map surrounded by walls(1) :
void is_surrounded(char **tab)
{
	int j;
	int i;

	j = 0;
	i = 0;
	if (ft_search(tab[j], '1') && ft_search(tab[ft_size(tab) - 1], '1'))
		{
			//printf("inside first if \n");
			j = 1;
			while (tab[j])
			{
				//printf("inside first while \n");
				if (tab[j][i] != '1' || tab[j][ft_strlen(tab[j]) - 1] != '1')
				{
					//printf("inside second if \n");
					exit_window();
				}	
			//printf("||| OK ||| \n");
			j++;
			}
		}
		else
		{
			//printf("inside else \n");
			exit_window();
		}
}

//size of the array :
int	ft_size(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		j++;
	return (j);
}
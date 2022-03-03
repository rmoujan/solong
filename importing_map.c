/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:20:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/03 09:20:35 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//import the map and put it inside an array 
void import_map(char ***tab, char *ptr)
{
	int fd;
	int k;
	int i;
	char *str;

	k = 0;
	fd = open(ptr ,O_RDONLY);
	while (get_next_line(fd))
		k++;
	*tab = (char **)malloc((k + 1) * sizeof(char*));
	close(fd);
	fd = open(ptr ,O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		(*tab)[i] =ft_strtrim(str, "\n");
		i++;
		str = get_next_line(fd);
	}
	(*tab)[i] = 0;
}
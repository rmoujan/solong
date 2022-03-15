/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:41:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/15 13:31:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (len_path < 4)
		ft_exit();
	if (ft_strcmp(path + len_path - 4, ".ber"))
		ft_exit();
}

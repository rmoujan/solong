/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:27:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/02 09:31:07 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
# define BUFFER_SIZE 10

typedef struct so_long	t_long;
struct	so_long {
	void	*mlx;
	void	*win;
};

char		*get_next_line(int fd);
char		*ft_strjoin(char **s1, char **s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
int			ft_checker(char *str);
char		*ft_process(char **rest);
void		*ft_free(char **p1);
char		*ft_work(char **buffer, char **rest, int fd);

#endif
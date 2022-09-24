/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:09:06 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 20:38:02 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct t_map{
	int		line;
	int		player;
	int		exit;
	int		collect;
	int		size;
	int		length;
	char	*map_data;

}	t_map;

//so_long
void print_error(int flag);

//check_map
t_map *check_map(char *map_filename);
void make_map_big(t_map *map);
int append_result(t_map *a, char *b);

//check_map_util
int check_data(t_map *map, char *line);
int is_wall(int count, char *line);
int is_valid(char *line, t_map *map);
int collect_data_map(t_map *map, char *line);
t_map	*init_map();
int check_last_wall(t_map *map);

// GNL
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*absolute_enter(int fd, char *BUFFER, char *backup);
char	*extract_result(char *result, char *backup);
char	*get_next_line(int fd);

#endif

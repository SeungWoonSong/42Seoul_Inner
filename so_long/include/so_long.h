/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:09:06 by susong            #+#    #+#             */
/*   Updated: 2022/09/26 08:59:04 by susong           ###   ########.fr       */
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

typedef struct t_game_data{
	int		line;
	int		player;
	int		exit;
	int		collect;
	int		size;
	int		length;
	char	*map_data;
	int		cur_x;
	int		cur_y;
	int		move;
	void	*mlx;
	void	*win;
	void	*p_collect;
	void	*p_exit;
	void	*p_player;
	void	*p_wall;
	void	*p_base;
	int		width;
	int		height;
	int		exit_flag;
}	t_game_data;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

//so_long
void		print_error(int flag);
void		start_game(t_game_data *map);
int			end_red(t_game_data *data);

//util_itoa
int			ft_count(long n);
char		*plusorminus(char *result, long n);
char		*ft_itoa(int n);

//check_map
int			check_map(t_game_data *game_data, char *map_filename);
void		make_map_big(t_game_data *map);
int			append_result(t_game_data *a, char *b);

//check_map_util
int			check_data(t_game_data *map, char *line);
int			is_wall(int count, char *line);
int			is_valid(char *line, t_game_data *map);
int			collect_data_map(t_game_data *map, char *line);
int			check_last_wall(t_game_data *map);

//draw_map
void		make_window(t_game_data *game_data);
void		draw_map(t_game_data *data, int index, int wid, int hei);
void		print_count(int count);
void		draw_map_util(int *hei, int *wid);

//control
int			key_press(int keycode, t_game_data *data);
void		set_game_data(t_game_data *param);
t_game_data	*init_data(void);
void		set_player(t_game_data *data);

//control2
void		move_left(t_game_data *data);
void		move_right(t_game_data *data);
void		move_up(t_game_data *data);
void		move_down(t_game_data *data);

// GNL
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*absolute_enter(int fd, char *BUFFER, char *backup);
char		*extract_result(char *result, char *backup);
char		*get_next_line(int fd);

#endif

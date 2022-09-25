/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:09:06 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 20:31:33 by susong           ###   ########.fr       */
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
	int		line; // map이 몇 줄인지?
	int		player; // player는 1개인지 확인
	int		exit; // 출구가 있는지 확인
	int		collect; // 수집해야되는 것의 수
	int		size; // 이 녀석이 받을 수 있는 map의 사이즈
	int		length; // 현재 map에 들어가 있는 길이(벡테 생각하면 됨)
	char	*map_data; // 실제 map_data
	int		cur_x; //캐릭터 현재 x 좌표
	int		cur_y; //캐릭터 현재 y 좌표
	int		move; // 총 얼마나 움직였는지?
	void	*mlx; // mlx 초기화용
	void	*win; // window 만들기용
	void	*p_collect;
	void	*p_exit;
	void	*p_player;
	void	*p_wall;
	void	*p_base;
	int		width; // 창 좌측 폭
	int		height; // 창 상하 폭
}	t_game_data;

typedef	struct t_param // 키 값을 입력 받고 정해진 동작을 수행했는지
{                      // 여부를 판단하기 위해 선언하였다.
	int x;               // x값
	int y;               // y값
} t_param;


#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인
#define X_EVENT_KEY_RELEASE 3

//so_long
void print_error(int flag);
void start_game(t_game_data *map);
t_game_data *end_red(t_game_data *data);


//util_itoa
int	ft_count(long n);
char	*plusorminus(char *result, long n);
char	*ft_itoa(int n);
//check_map
int check_map(t_game_data *game_data, char *map_filename);
void make_map_big(t_game_data *map);
int append_result(t_game_data *a, char *b);

//check_map_util
int check_data(t_game_data *map, char *line);
int is_wall(int count, char *line);
int is_valid(char *line, t_game_data *map);
int collect_data_map(t_game_data *map, char *line);

int check_last_wall(t_game_data *map);

//draw_map
void	make_window(t_game_data *game_data);
void	draw_map(t_game_data *data, int index, int wid, int hei);
void print_count(int count);
void	draw_map_util(int *hei, int *wid);

//control

int key_press(int keycode, t_game_data *data);
void set_game_data(t_game_data *param);
t_game_data	*init_data();
void	set_player(t_game_data *data);

//control2
void move_left(t_game_data *data);
void move_right(t_game_data *data);
void move_up(t_game_data *data);
void move_down(t_game_data *data);

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

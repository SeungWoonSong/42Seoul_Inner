#include <stdio.h>
#include <stdlib.h>
#include "./mlx/mlx.h"

#define KEY_ESC				53
#define KEY_W				13
#define KEY_S				1
#define	PRESS_RED_BUTTON	17
// 각 키보드를 눌렀을때의 전달값

typedef struct s_param{
	int		x;
	int		y;
}				t_param;
// 값을 저장할 구조체
void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}
// 구조체를 생성하고 값을 초기설정 해줌
int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)//W를 눌렀을때
		param->x++;
	else if (keycode == KEY_S) //S를 눌렀을때
		param->x--;
	else if (keycode == KEY_ESC) //ESC를 눌렀을때
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int	close(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param); // 구조체 값 초기설정
	mlx = mlx_init(); // mlx포인터 생성
	win = mlx_new_window(mlx, 500, 500, "key test");
    // 500x500 사이즈의 윈도우 띄우기
	printf("-------------------------------\n");
	printf("Start x = 3\n");
	mlx_key_hook(win, &key_press, &param);
    // 키보드의 입력을 받아 keypress 함수를 실행시키고 param의 매개변수를 활용함
    mlx_hook(win, PRESS_RED_BUTTON, 0, &close, &param);
    // 여러 종류의 입력을 받아 함수를 실행시킴
    // 17은 좌측상단의 끄기버튼을 눌렀을때 실행하도록 설정해줌
	mlx_loop(mlx);
    // 계속해서 키보드 입력을 받을 수 있도록 무한루프
}

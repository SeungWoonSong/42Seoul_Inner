#include "../include/pipex.h"

int main(int argc, char * const *argv, char **envp)
{
	char *arr[] = {"ls", "-al", NULL};
	int returnv = execve("/bin/ls", arr, envp);
	printf("\n\n\n\n\nhello value = %d\n", returnv);
}

// execve는 리눅스에서 실행했을 때의 결과를 만들어준다.
// TODO: envp 에 대해서 더 공부 필요


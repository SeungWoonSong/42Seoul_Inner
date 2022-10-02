#include "../include/pipex.h"

int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
    if (pid == 0)
    {
        printf("\n****자식프로세스****\n");
        printf("변수pid값: %d\n", pid);
        printf("자식피드: %d\n", getpid());
    }
    else
    {
        printf("\n****부모프로세스****\n");
        printf("변수pid값: %d\n", pid);
        printf("부모피드: %d\n", getpid());
    }
    return (0);
}

// 부모는 원래 자기가 가지고 있는 pid를 그대로 가지고, 자식은 0을 가지게 된다(pid값 기준)
// 각각의 프로세스 값은 또 다르다.

#include "../include/pipex.h"

int main(void)
{
    int fd1[2];
    int fd2[2];
    int fd3[2];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    printf("%d %d\n", fd1[0], fd1[1]);
    printf("%d %d\n", fd2[0], fd2[1]);
    printf("%d %d\n", fd3[0], fd3[1]);


//	Data can be written to the file descriptor fildes[1] and read from the file descriptor fildes[0].
//	A read on the file descriptor fildes[0] shall access data written to the file descriptor fildes[1] on a first-in-first-out basis. It is unspecified whether fildes[0] is also open for writing and whether fildes[1] is also open for reading.
// f[1] -> Write, f[0] -> READ
// 가서 읽어올 때 write 쓰면 FIFO형식으로 가져오게 된다.

}

/*************************************************************************
	> File Name: hello.c
	> Author: gjn135120
	> Mail:765164038@qq.com 
	> Created Time: Mon 15 Sep 2014 08:54:07 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int ERR;
ssize_t readn(int fd, void* buf, size_t len)
{
    size_t sum = 0;
    ssize_t n;
    char* msg = (char *)buf;
    while(sum < len)
    {
        n = read(fd, msg + sum, len - sum);
        if(n == -1)
        {
            if(ERR == EINTR)
                continue;
            return -1;
        }
        if(n == 0)
            break;
        sum += n;
    }
    return sum;
}

ssize_t sendn(int fd, const void *buf, size_t len)
{
    size_t sum = 0;
    ssize_t n;
    const char* msg = (const char *)buf;
    while(sum < len)
    {
        n = write(fd, msg + sum, len - sum);
        if(n <= 0)
        {
            if(n == -1 && ERR == EINTR)
                continue;
            return -1;
        }
        sum += n;
    }
    return len;
}
int main(int argc, const char *argv[])
{
    
    int fd[2];
    pipe(fd);
    char buf[30], str[100];
    memset(buf, 0, 30);
    memset(str, 0, 100);
    if(fork() == 0)
    {
        close(fd[1]);
        int cnt = readn(fd[0], (void*)buf, 20);
        printf("recv : %d \n", cnt);
        printf("%s\n", buf);
        close(fd[0]);
        exit(0);
    }
    else
    {
        close(fd[0]);
        fgets(str, 100, stdin);
        int s = sendn(fd[1], (void*)str, strlen(str));
        printf("send : %d\n", s);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}


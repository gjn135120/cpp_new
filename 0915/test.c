/*************************************************************************
	> File Name: test.c
	> Author: gjn135120
	> Mail:765164038@qq.com 
	> Created Time: Mon 15 Sep 2014 04:00:46 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern int errno;
ssize_t readn(int fd, void *buf, size_t cnt)
{
    size_t k = cnt;  //剩余字节数
    ssize_t n = 0;   //返回值
    char *msg = (char *)buf;
    while(k > 0)
    {
        n = read(fd, msg, k);
        if(n == -1 )
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        if(n == 0)
            break;
        msg += n;
        k -= n;
    }
    return cnt - k;
}
ssize_t sendn(int fd, const void *buf, size_t cnt)
{
    size_t k = cnt;
    ssize_t n = 0;
    const char *msg = (const char *)buf;
    while(k > 0)
    {
        n = write(fd, msg, k);
        if(n <= 0)
        {
            if(n == -1 && errno == EINTR)
                continue;
            return -1;
        }
        msg += n;
        k -= n;
    }
    return cnt;
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


#include "unp.h"
#include <time.h>

// 使用Uinx Domain套接字
int main(int argc, char **argv) {
    int connfd;
    socklen_t len, addrlen;
    char buff[MAXLINE];
    time_t ticks;
    struct sockaddr_storage cliaddr;
    struct sockaddr_un addr;
    int sockfd;

    sockfd = Socket(AF_LOCAL, SOCK_STREAM, 0);
    unlink(UNIXSTR_PATH);

    bzero(&addr, sizeof(addr));
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, UNIXSTR_PATH, sizeof(addr.sun_path) - 1);
    Bind(sockfd, (SA *)&addr, SUN_LEN(&addr));

    Listen(sockfd, LISTENQ);
    for (;;) {
        len = sizeof(cliaddr);
        connfd = Accept(sockfd, (SA *)&cliaddr, &len);
        // 对于Unix Domain套接字来说sock_ntop会有问题
        // printf("connection from %s\n", Sock_ntop((SA *)&cliaddr, len));

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        for (char *p = buff; *p != '\0'; p++) {
            Write(connfd, p, 1);
        }
        // Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
}

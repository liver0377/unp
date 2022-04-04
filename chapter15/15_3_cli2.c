#include "unp.h"

// 使用Unix Domain套接字
int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    socklen_t len;
    struct sockaddr_storage ss;
    struct sockaddr_un addr;
    if (argc != 1)
        err_quit("usage: 15_3_cli2.o ");

    // sockfd = Tcp_connect(argv[1], argv[2]);
    sockfd = Socket(AF_LOCAL, SOCK_STREAM, 0);
    addr.sun_family = AF_LOCAL;
    strncpy(&addr.sun_path, UNIXSTR_PATH, sizeof(addr.sun_path) - 1);
    Connect(sockfd, (SA *)&addr, sizeof(addr));

    len = sizeof(ss);
    Getpeername(sockfd, (SA *)&ss, &len);
    printf("connected to %s\n", Sock_ntop_host((SA *)&ss, len));
    // sleep
    sleep(5);
    while ((n = Read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0; /* null terminate */
        Fputs(recvline, stdout);
        printf("read bytes: %d\n", n);
    }
    exit(0);
}

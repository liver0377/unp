#include "unp.h"

void sig_handler(int signo) {
    printf("caught signal!\n");
    return;
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: tcpcli <IPaddress>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    // change the server port to 13
    servaddr.sin_port = htons(13);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    // add signal handler
    Signal(SIGCHLD, sig_handler);

    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));
    sleep(2);
    Write(sockfd, "hello", 5);
    sleep(2);
    Write(sockfd, "hello", 5);

    exit(0);
}
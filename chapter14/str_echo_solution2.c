#include "unp.h"

void str_echo(int sockfd) {
    // 标准ANSIC IO
    char line[MAXLINE];
    FILE *fpin, *fpout;
    fpin = Fdopen(sockfd, "r");
    fpout = Fdopen(sockfd, "w");

    while (Fgets(line, MAXLINE, fpin) != NULL) {
        Fputs(line, fpout);
        fflush(fpout);
    }
}

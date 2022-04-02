#include "unp.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: ./11_11.o name\n");
        exit(-1);
    }

    struct hostent *h;
    char **p;
    char str[INET_ADDRSTRLEN];
    struct in_addr addr;
    Inet_pton(AF_INET, argv[1], &addr);
    if ((h = gethostbyaddr(&addr, sizeof(struct in_addr), AF_INET)) != NULL) {
        printf("\tname: %s\n", h->h_name);
        for (p = h->h_addr_list; *p != NULL; p++) {
            printf("\taddress: %s\n",
                   Inet_ntop(h->h_addrtype, *p, str, sizeof(str)));
        }
    } else {
        printf("not found\n");
    }
}
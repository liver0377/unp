#include "../include/unp.h"
#include <stdio.h>

int inet_pton_loose(int family, const char *strptr, void *addrptr) {
    if (family != AF_INET && family != AF_INET6)
        return -1;
    if (inet_pton(family, strptr, addrptr)) {
        printf("inet_pton() pass!\n");
    } else if (inet_aton(strptr, addrptr)) {
        printf("inet_aton() pass!\n");
    } else {
        return -1;
    }
    return 1;
}
char buf[100];
void test1(char *str) {
    if (inet_pton_loose(AF_INET, str, buf) == 1) {
        printf("%s\n", buf);
    } else {
        printf("error!\n");
    }
}

void test2(char *str) {
    if (inet_pton_loose(AF_INET6, str, buf) == 1) {
        printf("%s\n", buf);
    } else {
        printf("error!\n");
    }
}
int main() {
    char *str_1 = "111.111.111.111"; // 点分十进制
    char *str_2 = "0x6f6f6f6f";      // 十六进制
    char *str_3 = "0157";
    printf("ipv4 test:\n");
    test1(str_1);
    test1(str_2);
    test1(str_3);
    printf("ipv6 test:\n");
    test2(str_1);
    test2(str_2);
    test2(str_3);
    return 0;
}
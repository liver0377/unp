#include	"unp.h"

int
main(int argc, char **argv)
{
	char			*ptr, **pptr;
	char			str[INET_ADDRSTRLEN];
	struct hostent	*hptr;
	struct hostent  *hptr_new = (struct hostent*)malloc(sizeof(struct hostent));
    struct in_addr  addr;
	while (--argc > 0) {
		ptr = *++argv;
		hptr_new->h_addr_list = 0;
		hptr_new->h_addrtype  = 0;
		hptr_new->h_aliases   = 0;
		hptr_new->h_length    = 0;
		hptr_new->h_name      = 0;
		if ( (hptr = gethostbyname(ptr)) == NULL) {
			err_msg("gethostbyname error for host: %s: %s",
					ptr, hstrerror(h_errno));
			continue;
		}
		// 拷贝gethostbyname分配的static hosten结构
        memcpy(hptr_new, hptr, sizeof(struct hostent));
		
		printf("official hostname: %s\n", hptr_new->h_name);

		for (pptr = hptr_new->h_aliases; *pptr != NULL; pptr++)
			printf("\talias: %s\n", *pptr);

		switch (hptr_new->h_addrtype) {
		case AF_INET:
			pptr = hptr_new->h_addr_list;
			for ( ; *pptr != NULL; pptr++) {
                printf("\taddress: %s\n",
			 		Inet_ntop(hptr_new->h_addrtype, *pptr, str, sizeof(str)));
               
                if ((hptr = gethostbyaddr(*pptr, hptr_new->h_length, hptr_new->h_addrtype)) == NULL) {
					printf("\t(gethostbyaddr failed)\n");
				} else if (hptr->h_name != NULL) {
					printf("\tname = %s\n", hptr->h_name);
				} else {
					printf("\t (no hostname returned by gethostbyaddr)\n");
				}

			}
				
			break;

		default:
			err_ret("unknown address type");
			break;
		}
	}
	exit(0);
}

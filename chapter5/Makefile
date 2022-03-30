5_1: tcpserv.c tcpcli.c
	gcc -w -o tcpserv.o tcpserv.c ../libunp.a -lpthread
	gcc -w -o tcpcli.o tcpcli.c ../libunp.a -lpthread

5_6: tcpserv_1.c tcpcli_1.c
	gcc -w -o tcpserv_1.o tcpserv_1.c ../libunp.a -lpthread
	gcc -w -o tcpcli_1.o tcpcli_1.c ../libunp.a -lpthread

clean: 
	rm ./*.o

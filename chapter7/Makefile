all: 8_7_client.c dgcliloop.c 8_7_server.c dgecholoop.c 
	gcc -w -o 8_7_client.o 8_7_client.c dgcliloop.c ../libunp.a 
	gcc -w -o 8_7_server.o 8_7_server.c dgecholoop.c ../libunp.a	
	gcc -w -o 8_7_client_p.o 8_7_client.c dgcliloop_p.c ../libunp.a 
	gcc -w -o 8_7_server_p.o 8_7_server.c dgecholoop_p.c ../libunp.a	

8_7_client: 8_7_client.c dgcliloop.c 
	gcc -w -o 8_7_client.o 8_7_client.c dgcliloop.c ../libunp.a 

8_7_server: 8_7_server.c dgecholoop.c
	gcc -w -o 8_7_server.o 8_7_server.c dgecholoop.c ../libunp.a

8_7_client_p: 8_7client.c dgcliloop_p.c
	gcc -w -o 8_7_client_p.o 8_7_client.c dgcliloop_p.c ../libunp.a 

8_7_server_p: 8_7_server.c dgecholoop_p.c
	gcc -w -o 8_7_server_p.o 8_7_server.c dgecholoop_p.c ../libunp.a

clean:
	rm ./*.o
all: 11_1.c 11_2.c 11_3_cli.c 11_3_serv.c
	gcc -w -o 11_1.o 11_1.c ../libunp.a
	gcc -w -o 11_2.o 11_2.c ../libunp.a
	gcc -w -o 11_3_cli.o 11_3_cli.c ../libunp.a
	gcc -w -o 11_3_serv.o 11_3_serv.c ../libunp.a
	
11_1: 11_1.c
	gcc -w -o 11_1.o 11_1.c ../libunp.a 

11_2: 11_2.c
	gcc -w -o 11_2.o 11_2.c ../libunp.a

11_3: 11_3_cli.c 11_3_serv.c
	gcc -w -o 11_3_cli.o 11_3_cli.c ../libunp.a
	gcc -w -o 11_3_serv.o 11_3_serv.c ../libunp.a

11_11: 11_11.c
	gcc -w -o 11_11.o 11_11.c ../libunp.a

clean:
	rm ./*.o
all: 15_3_cli.c 15_3_serv.c 15_3_cli2.c 15_3_serv2.c 15_4.c
	gcc -w -o 15_3_cli.o 15_3_cli.c ../libunp.a
	gcc -w -o 15_3_serv.o 15_3_serv.c ../libunp.a
	gcc -w -o 15_3_serv2.o 15_3_serv2.c ../libunp.a
	gcc -w -o 15_3_cli2.o 15_3_cli2.c ../libunp.a	
	gcc -w -o 15_4.o 15_4.c ../libunp.a

15_3: 15_3_cli.c 15_3_serv.c 15_3_cli2.c 15_3_serv2.c
	gcc -w -o 15_3_cli.o 15_3_cli.c ../libunp.a
	gcc -w -o 15_3_serv.o 15_3_serv.c ../libunp.a
	gcc -w -o 15_3_serv2.o 15_3_serv2.c ../libunp.a
	gcc -w -o 15_3_cli2.o 15_3_cli2.c ../libunp.a

15_4: 15_4.c
	gcc -w -o 15_4.o 15_4.c ../libunp.a

clean:
	rm ./*.o
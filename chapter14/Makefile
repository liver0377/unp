14_5: 14_5_cli.c 14_5_serv.c str_echo.c str_cli.c str_echo_solution1.c str_echo_solution2.c
	gcc -w -o 14_5_cli.o 14_5_cli.c str_cli.c ../libunp.a 
	gcc -w -o 14_5_serv.o 14_5_serv.c str_echo.c ../libunp.a
	gcc -w -o 14_5_serv_solution1.o 14_5_serv.c str_echo_solution1.c ../libunp.a
	gcc -w -o 14_5_serv_solution2.o 14_5_serv.c str_echo_solution2.c ../libunp.a

clean: 
	rm ./*.o
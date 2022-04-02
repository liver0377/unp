#!/usr/bin/sh

# connection refused问题无法解决
make
./11_3_serv.o &
PID=$(pidof 11_3_serv.o)
sleep 1
./11_3_cli.o VM-12-15-ubuntu chargen
kill ${PID}
make clean

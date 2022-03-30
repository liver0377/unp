#!/usr/bin/sh

make 5_6

./tcpserv_1.o &

sleep 1
PID=$(pidof tcpserv_1.o)
echo ${PID}

./tcpcli_1.o 127.0.0.1

kill ${PID}
make clean

#!/usr/bin/sh

make 15_3

echo 'TCP test'
./15_3_serv.o 9999 &
sleep 1
./15_3_cli.o 127.0.0.1 9999

PID=$(pidof 15_3_serv.o)
kill ${PID}

sleep 3
echo 'Unix Domain test'
./15_3_serv2.o &
sleep 1
./15_3_cli2.o
PID=$(pidof 15_3_serv2.o)
kill ${PID}

make clean

#!/usr/bin/sh

make
echo '完全缓冲:'
./14_5_serv.o &
sleep 1
./14_5_cli.o 127.0.0.1
PID=$(pidof 14_5_serv.o)
kill ${PID}

echo '行缓冲'
./14_5_serv_solution1.o &
sleep 1
./14_5_cli.o 127.0.0.1
PID=$(pidof 14_5_serv_solution1.o)
kill ${PID}

echo '强制刷新'
./14_5_serv_solution2.o &
sleep 1
./14_5_cli.o 127.0.0.1
PID=$(pidof 14_5_serv_solution2.o)
kill ${PID}
make clean

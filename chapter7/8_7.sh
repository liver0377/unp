#!/usr/bin/sh

make all

echo 'test1: no print'
./8_7_server.o &
./8_7_client.o 127.0.0.1
PID=$(pidof 8_7_server.o)
kill -n SIGINT ${PID}

echo 'test2: print in client'
./8_7_server.o &
./8_7_client_p.o 127.0.0.1
PID=$(pidof 8_7_server.o)
kill -n SIGINT ${PID}

echo 'test3: print in server'
./8_7_server_p.o &
./8_7_client.o 127.0.0.1
PID=$(pidof 8_7_server_p.o)
kill -n SIGINT ${PID}

make clean

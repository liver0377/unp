#!/usr/bin/sh
make

./tcpserv.o &
sleep 1

PID=$(pidof tcpserv.o)
echo ${PID}

echo 'please press ^D'
./tcpcli.o 127.0.0.1

declare -i COUNT
COUNT=0
while true; do
    date "+%Y_%m_%d %H:%M:%S"
    STR=$(netstat -a | grep TIME_WAIT | grep 9877)
    echo ${STR}
    if [ -z "${STR}" ]; then
        break
    fi
    sleep 5
    COUNT=${COUNT}+5
done

kill ${PID}
COUNT=${COUNT}/2
echo "MSL = ${COUNT}"
make clean

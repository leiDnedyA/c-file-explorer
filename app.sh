#!/bin/sh

gcc main.c -lncurses

sleep 0.1

./a.out

kill -9 $PPID


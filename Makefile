#-*- Makefile -*-

main: main.o functions.o
	gcc main.o functions.o -o main

main.o: main.c prototypes.h
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

clean:
	del functions.o main.o main.exe




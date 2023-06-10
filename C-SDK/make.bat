@echo off
if ["%*"]==["compile"] GOTO COMPILAR
if ["%*"]==["run"] GOTO CORRER
if ["%*"]==["runarg"] GOTO CORRERARG
GOTO FIN

:COMPILAR
gcc -c -Wall -Werror -fpic -o ./CODE/libreria.o ./CODE/libreria.c
gcc -shared -o ./SDK/liblibreria.dll ./CODE/libreria.o
copy CODE\libreria.h SDK\libreria.h
del CODE\libreria.o
copy SDK\liblibreria.dll Release\liblibreria.dll
gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
gcc -L./SDK   main.o  -llibreria  -o ./Release/main.exe
del main.o 
GOTO FIN

:CORRER
set PATH=%PATH%;%CD%/Release
Release\main.exe 
GOTO FIN

:CORRERARG
set PATH=%PATH%;%CD%/Release
Release\main.exe Persona.txt
GOTO FIN

:FIN

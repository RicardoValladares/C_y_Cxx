@echo off
if ["%*"]==["compile"] GOTO COMPILAR
if ["%*"]==["run"] GOTO CORRER
if ["%*"]==["runarg"] GOTO CORRERARG
GOTO FIN

:COMPILAR
gcc -c -Wall -Werror -fpic -o ./CODE/library.o ./CODE/library.c
gcc -shared -o ./SDK/liblibrary.dll ./CODE/library.o
copy CODE\library.h SDK\library.h
del CODE\library.o
copy SDK\liblibrary.dll Release\liblibrary.dll
gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
gcc -L./SDK   main.o  -llibrary  -o ./Release/main.exe
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

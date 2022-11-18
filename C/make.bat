@echo off
if ["%*"]==["compile"] GOTO COMPILAR
if ["%*"]==["run"] GOTO CORRER
if ["%*"]==["runarg"] GOTO CORRERARG
GOTO FIN

:COMPILAR
gcc main.c -o ./build/main.exe
GOTO FIN

:CORRER
build\main.exe
GOTO FIN

:CORRERARG
build\main.exe Persona.txt
GOTO FIN

:FIN

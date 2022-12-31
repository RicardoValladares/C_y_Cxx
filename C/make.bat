@echo off
if ["%*"]==["compile"] GOTO COMPILAR
if ["%*"]==["run"] GOTO CORRER
if ["%*"]==["runarg"] GOTO CORRERARG
GOTO FIN

:COMPILAR
gcc main.c -o ./dist/Windows.exe
GOTO FIN

:CORRER
dist\Windows.exe
GOTO FIN

:CORRERARG
dist\Windows.exe Persona.txt
GOTO FIN

:FIN

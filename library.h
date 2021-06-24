#include "unistd.h" 
#include "stdio.h" 
#include "stdlib.h"

void print(char string[256]); //print chars
void scan(char outstring[256]); //read chars not space
void pausa(int segundos); //pausa
int ctoi(char* string); //char to int
char* itoc(int integer); //int to char



void concat(char string[],int length, ...);


/*
 //pausa 5 second
 //return size of chars
//int cpchars(char INstring[], char OUTstring[], int OUTlength); //copy chars in other chars
//int clchar(char ascii, char* character); //code ascii to char valido
 //concat chars1 + chars2 = chars
//void vprint(int length, ...); //print varibles
int fprint(char filename[], int length, ...); //file print
int fscan(char filename[], char** chars);
*/
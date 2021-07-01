#include "unistd.h" 
#include "stdlib.h" 
#include "stdio.h" 


int atoc(int ascii, char* character);

int ctoi(char string[10], int* integer);

int itoc(int integer, char string[10]);

int concat(char string[], char *first, ...);

void print(char string[]);

void scan(char string[], int length);

void pausa(int segundos);

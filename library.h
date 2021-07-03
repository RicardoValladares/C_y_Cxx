#include "unistd.h" 
#include "stdlib.h" 
#include "stdio.h" 


int atoc(int ascii, char* character);
int ctoi(char string[], int* integer);
int itoc(int integer, char string[10]);
void print(char string[]);
void scan(char string[], int length);
void pausa(int segundos);
int fscan(char filename[], char text[256][256], int* line);






int concat(char string[], char *first, ...);

#include "unistd.h" 
#include "stdlib.h" 
#include "stdio.h" 


int atoc(int ascii, char* character);
int itoc(int integer, char string[10]);
void print(char string[]);
void scan(char string[], int length);
void pausa(int segundos);
int concat(char string[], char *first, ...);
int ctoi(char string[], int* integer);
int scantxt(char filename[], char text[256][256], int* line);
int newtxt(char filename[]);
int printxt(char filename[], char string[]);

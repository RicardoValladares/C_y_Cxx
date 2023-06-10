#ifndef ___LIBRARY___
#define __LIBRARY___
 
void pausa(int segundos); 
void clear(); 
 
int itoc(int integer, char string[10]); 
int ctoi(char string[], int* integer); 
int concat(char string[], char *first, ...); 
int atoc(int ascii, char* character); 
 
void print(char string[]); 
void scan(char string[], int length); 
 
int printxt(char filename[], char string[]); 
int scantxt(char filename[], char text[100][100], int* line); 
int newtxt(char filename[]); 
 
#endif

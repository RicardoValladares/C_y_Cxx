#include "unistd.h" 
#include "stdlib.h" 
#include "stdio.h" 

void inichars(char string[], int length); //

int cpchars(char INstring[], char OUTstring[], int OUTlength);

int clchar(char ascii, char* character);

int ctoi(char string[10], int* integer);

void pausa(int segundos);

void print(char string[]);

void scan(char outstring[]);

void scants(char outstring[]);

int length(char string[]);

void concat(char INstring1[], char INstring2[], char OUTstring[]);

void printv(int length, ...);

void itoc(int integer, char string[10]);
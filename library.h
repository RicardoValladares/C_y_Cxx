#include "unistd.h" 
#include "stdlib.h" 

void init_chars(char string[], int length);

int copy_chars(char INstring[], char OUTstring[], int OUTlength);

int clean_char(char ascii, char* character);

int ctoi(char string[10], int* integer);

void pausa(int segundos);
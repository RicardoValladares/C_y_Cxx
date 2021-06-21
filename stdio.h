#include <stdio.h>

void print(char string[]){
	printf("%s",string);
}

void println(char string[]){
	printf("%s\n",string);
}

void scan(char outstring[]){
	int i = 0;
	int byte = 0;
	char string[30];
	for(i=0; i<30; i++){
		outstring[i] = 0;
		string[i] = 0;
	}
	fgets(string, 31, stdin);
	for(i=0; i<30; i++){
		byte = string[i];
		if(byte>=32 && byte<=126){
			outstring[i] = byte;
		}
	}
}

void scants(char outstring[]){
	int i = 0;
	int puntero = 0;
	int byte = 0;
	char string[30];
	for(i=0; i<10; i++){
		outstring[i] = 0;
		string[i] = 0;
	}
	fgets(string, 11, stdin);
	for(i=0; i<10; i++){
		byte = string[i];
		if(byte>=33 && byte<=126){
			outstring[puntero] = byte;
			puntero = puntero + 1;
		}
	}
}

#include <stdlib.h>
#include <stdarg.h>

int ctoi(char string[10]){
	int byte, point;
	int sucecion[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	int psucecion=0;
	int integer=0;
	for(point=0; point<10; point++) {
		byte = string[9-point];
		if(byte<=57 && byte>=48){
			byte = string[9-point] - '0';
			integer = integer + (byte *sucecion[psucecion++]);
			printf("%s\n", "entro");
		}
	}
	if(string[0]==45 && integer!=0){
		integer = 0 - integer;
	}
	return integer;
}
char* itoc(int integer){
	static char string[10];
	char buffer[10];
	int byte; 
	int point = 0;
	int psucecion = 0;
	if(integer<0){ string[0] = '-'; }
	if(integer<0){ psucecion=1; integer = abs(integer); }
	do{
		byte = integer % 10;
		buffer[point] = byte + '0';
		integer = integer / 10;
		point = point + 1;
	}while(integer!=0);
	for(point=0; point<10; point++) {
		byte = buffer[9-point] - '0';
		if(byte<=9 && byte>=0){
			string[psucecion] = byte + '0';
			psucecion++;
		}	
	}
	return string;
}

/*int length(char string[]){
	int puntero=0;
	char byte;
	byte = string[0];
	while(byte>=32 && byte<=126){
		puntero = puntero+1;
		byte = string[puntero];
		printf("%c %d\n",byte,puntero);
	}
	return puntero;
}*/


void concat(char string[],int length, ...){
	char* argumento;
	int larg=0;
	int parg;
	int point;
	char byte;
	va_list list;
	va_start(list, length);
	//static char string[256];
	for(parg=0; parg<length; parg++){
		argumento = va_arg(list, char*);
		point = 0;
		byte = argumento[0];
		while(byte>=32 && byte<=126){
			string[larg] = byte;
			point = point+1;
			byte = argumento[point];
			larg++;
		}
	}
	va_end(list);
	//printf("%d -%s-\n",larg,string);
}


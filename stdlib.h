#include <stdlib.h>
#include <stdarg.h>

//#define va_start(__list,__parmN) __list = (char *)((unsigned long)&(__parmN) \ + (((sizeof(__parmN)+7)/8)*8))

int ctoi(char* string){
	int byte, point;
	int sucecion[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	int psucecion=0;
	int integer=0;
	for(point=0; point<10; point++) {
		byte = string[9-point];
		if(byte<=57 && byte>=48){
			byte = string[9-point] - '0';
			integer = integer + (byte *sucecion[psucecion++]);
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
	}
	return puntero;
}
*/

char* concat(int length, ...){
	char* argumento;
	char* string;
	int byte;
	va_list list;
	va_start(list, length);
	int i;

	char* OUTstring;
	int OUTpuntero;
	do{
		argumento = va_arg(list, char*);
		OUTpuntero = 0;
		byte = argumento[OUTpuntero];
		while((byte>=32 && byte<=126)||byte==10||byte==9){
			OUTstring[OUTpuntero] = byte;
			OUTpuntero = OUTpuntero + 1;
			INpuntero = INpuntero + 1;
		}
		
		printf("%c\n",argumento[0]);
   	}while(argumento[0]>=32 && argumento[0]<=126);
	va_end(list);

	return "OK";


	/*
	int OUTpuntero=0;
	int INpuntero=0;
	int byte;
	byte = INstring1[0];
	while(byte>=32 && byte<=126){
		OUTstring[OUTpuntero] = byte;
		OUTpuntero = OUTpuntero + 1;
		INpuntero = INpuntero + 1;
		byte = INstring1[INpuntero];
	}
	INpuntero = 0;
	byte = INstring2[0];
	while(byte>=32 && byte<=126){
		OUTstring[OUTpuntero] = byte;
		OUTpuntero = OUTpuntero + 1;
		INpuntero = INpuntero + 1;
		byte = INstring2[INpuntero];
	}*/
}


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


char* concat(int length, ...){
	/*char* argumento;
	char* string;
	int byte;
	va_list list;
	va_start(list, length);
	int i;*/

/*
	char OUTstring[10];
	int OUTpuntero=0;
	int p;
	for(i=0; i<length; i++){
		argumento = va_arg(list, char*);
		int d = length(argumento);
		printf("%d\n",argumento);
		p=0;
		do{
			
			byte = argumento[p];
			
			if((byte>=32 && byte<=126)||byte==10||byte==9){
				//printf("%d\n",byte);
				OUTstring[OUTpuntero] = byte;
				//printf("%c\n",OUTstring[OUTpuntero]);
				OUTpuntero = OUTpuntero + 1;
			}

			p++;
		}while((byte>=32 && byte<=126)||byte==10||byte==9);
		//printf("%d\n",i);
   	}
	va_end(list);

*/
	/*
	// EL SIZE DE SALIDA SERA DE 256 AUNQUE NO USE TODO PERO EL NUMERO DE ITERACIONES SERA IGUAL A LA SUMA
	int suma=0;
	for(i=0; i<length; i++){
		argumento = va_arg(list, char*);
		int puntero=0;
		char byte;
		byte = string[0];
		while(byte>=32 && byte<=126){
			puntero = puntero+1;
			byte = argumento[puntero];
			suma++;
		}
	}
	va_end(list);
	//printf("%d\n",suma);
	*/

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


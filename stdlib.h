#include <stdlib.h>
#include <stdarg.h>

int atoc(char ascii, char* character){
	int byte = ascii;
	if(byte>=33 && byte<=126){
		*character = byte;
		return 1;
	}
	else{
		*character = 32;
		return -1;
	}
}

int ctoi(char string[10], int* integer){  
	int estado;
	int counter = 0;
	int counter2 = 0;
	int byte, nextbyte, point;
		int sucecion[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
		int psucecion=0;
		for(point=0; point<10; point++) {
			byte = string[9-point];
			if(byte==57){
				counter2++;
			}
			if(byte<=57 && byte>=48){
				byte = string[9-point] - '0';
				*integer = *integer + (byte *sucecion[psucecion++]);
				counter++;
			}
		}
		if(string[0]==45 && *integer!=0){
			*integer = 0 - *integer;
		}
		if(counter2==10){
			*integer = 0;
			return -1;
		}
		if(counter>0){
			return 1;
		}
		else{
			*integer = 0;
			return -1;
		}
}


int itoc(int integer, char string[10]){
		int point = 0;
		char buffer[10];
		int byte; 
		int psucecion = 0;
		if(integer<0){ 
			string[0] = '-'; 
			psucecion=1; 
			integer = abs(integer); 
		}
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
		return 1;
}









void concat(char string[], char *first, ...){

	int primero = 1;
	int punterof = -1;
	
	int larg=0;
	int point;
	char byte;
	va_list argptr;
    char *next;
    va_start (argptr, first);
    next = first;
    while (next) {
        point = 0;
		byte = next[0];
        while(byte>=32 && byte<=126){
        	if(primero==1){
        		punterof++;
        	}
   			string[larg] = byte;
   			point = point+1;
   			byte = next[point];
   			larg++;
   		}
   		primero = 0;
        next = va_arg(argptr, char*);
    }
    larg--;
    va_end (argptr);
	//printf("%d",larg);
	int i;
	for(i=0;i<=punterof;i++){

		
		
		if( string[larg-i] == first[punterof-i] ){
			string[larg-i] = 0;
		}
		else if(string[larg-i]<=33 || string[larg-i]>=126){
			string[larg-i] = 0;
		}

		
		
	}
	
}


#include <stdarg.h>

int atoc(int ascii, char* character){
	if(ascii>=32 && ascii<=126){
		*character = ascii;
		return 1;
	}
	else{
		*character = 0;
		return -1;
	}
}

int ctoi(char string[10], int* integer){  
	int ascii, point;
	int digits = 0;
	int overflow = 0;
	int unit[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	for(point=0; point<10; point++) {
		ascii = string[9-point];
		if(ascii==57){
			overflow++;
		}
		if(ascii<=57 && ascii>=48){
			ascii = string[9-point] - '0';
			*integer = *integer + (ascii * unit[digits++]);
		}
	}
	if(string[0]==45 && *integer!=0){
		*integer = 0 - *integer;
	}
	if(overflow<10 && digits>0){
		return 1;
	}
	else{
		*integer = 0;
		return -1;
	}
}


int itoc(int integer, char string[10]){
	int digit;
	int point = 0;
	int length = 0;
	char buffer[10];
	if(integer<0){ 
		string[length] = '-'; 
		length = 1; 
		integer = integer * (-1); 
	}
	do{
		digit = integer % 10;
		buffer[point] = digit + '0';
		integer = integer / 10;
		point++;
	}while(integer);
	for(point=0; point<10; point++) {
		digit = buffer[9-point] - '0';
		if(digit<=9 && digit>=0){
			string[length] = digit + '0';
			length++;
		}	
	}
	return 1;
}

int concat(char string[], char *first, ...){
	int point;
	char character;
	char *token;
	int length=0;
	int pointfirst = 0;
	int isfirst = 1;	
	va_list args;
	va_start(args, first);
	token = first;
    while(token){
        point = 0;
		character = token[point];
        while(character>=' ' && character<='~'){
        	if(isfirst==1){
        		pointfirst++;
        	}
   			string[length] = character;
   			point = point+1;
   			character = token[point];
   			length++;
   		}
   		isfirst = 0;
        token = va_arg(args, char*);
    }
    length--;
    pointfirst--;
    va_end(args);
	for(point=0;point<=pointfirst;point++){
		if(string[length-point] == first[pointfirst-point]){
			string[length-point] = 0;
		}
		else if(string[length-point]<=33 || string[length-point]>=126){
			string[length-point] = 0;
		}
	}
	if(pointfirst<0 || length<0){
		string[0] = 0;
		return -1;
	}
	else{
		return 1;
	}
}


#include <stdarg.h>
#include <stdio.h>

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

int ctoi(char string[], int* integer){  
	int ascii, limit;
	int point = 0;
	int length = 0;
	int digits = 0;
	int overflow = 0;
	*integer = 0;
	int unit[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	if(string[0]==45 && (string[1]<=57 || string[1]>=48)){
		limit = 1;
	}
	else if(string[0]<=57 || string[0]>=48){
		limit = 0;
	}
	else{
		return -1;	
	}
	do{
		ascii = string[point];
		point = (ascii==45 || (ascii<=57 && ascii>=48)) ? point+1 : point;
		if(ascii!=45 && (ascii>57 || ascii<48)){
			length = point;
		}
	}while(length==0);
	if(length>10){
		return -1;	
	}
	for(point=(length-1); point>=limit; point--) {
		ascii = string[point];
		if(ascii<=57 && ascii>=48){
			*integer = (*integer) + ((ascii - '0') * unit[digits++]);
		}
		if(*integer>1400000000){
			overflow = 1;
			point = -1;
		}
	}
	if(overflow==1 || digits==0){
		*integer = 0;
		return -1;
	}
	if(string[0]==45){
		*integer = 0 - *integer ;	
	}
	return 0;
	
}

int itoc(int integer, char string[10]){
	int digit;
	int point = 0;
	int length = 0;
	char buffer[10];
	if(integer<0){ 
		string[length] = '-'; 
		length = 1; 
		integer *= (-1); 
	}
	do{
		digit = integer % 10;
		buffer[point] = digit + '0';
		integer /= 10;
		point++;
	}while(integer);
	for(point=0; point<10; point++) {
		digit = buffer[9-point] - '0';
		string[length] = (digit<=9 && digit>=0) ? digit + '0' : 0;
		length++;	
	}
	return 1;
}

int concat(char string[], char *first, ...){
	int point;
	char character;
	char *token;
	int length = 0;
	int pointfirst = 0;
	int isfirst = 1;	
	va_list args;
	va_start(args, first);
	token = first;
    while(token){
        point = 0;
		character = token[point];
        while((character>=32 && character<=126) || (character==10)){
        	if(isfirst==1){
        		pointfirst++;
        	}
   			string[length] = character;
   			point++;
   			character = token[point];
   			length++;
   		}
   		isfirst = 0;
        token = va_arg(args, char*);
    }
    length--;
    pointfirst--;
    va_end(args);
	for(point=0; point<=pointfirst; point++){
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


#include <stdio.h>
#include <stdarg.h>

void print(char* string){
	printf("%s",string);
}
char* scan(int length){
	char* outstring;
	int i = 0;
	int puntero = 0;
	int byte = 0;
	char string[length];
	for(i=0; i<length; i++){
		outstring[i] = 0;
		string[i] = 0;
	}
	fgets(string, (length+1), stdin);
	for(i=0; i<length; i++){
		byte = string[i];
		if(byte>=33 && byte<=126){
			outstring[puntero] = byte;
			puntero = puntero + 1;
		}
	}
	return outstring;
}

/*int fprint(char filename[], int length, ...){
	FILE *file = fopen(filename,"a+");
	if(file == NULL){
		return 0;
	}
	else{	
		int i;
		char* argumento;
		va_list list;
		va_start(list, length);
		for(i = 0; i<length; i++){
			argumento = va_arg(list, char*);
			fprintf(file,"%s",argumento);
		}
		va_end(list);
		fclose(file);
		return 1;
	}
}
int fscan(char filename[], char** chars){
	FILE *archivo = fopen(filename, "r");
	char caracter;
	int estado, x, y;
	x=0;
	y=0;
	if(archivo == NULL){ 
		return 0;
	}
	else{
		while((caracter = fgetc(archivo)) != EOF){ // char read("url",i)
			int byte = caracter;
			if(byte>=33 && byte<=126){
				caracter = byte;
			}
			else{
				caracter=32;
			}

			if(caracter==10){ 
				chars[x][y] = caracter;
				y++;
				//chars[x][y]

				//NewLine
				//plineal = plineal + 1;
				//puntero = 0;
			}
			else{
				chars[x][y] = caracter;
				x++;
			}
			//puntero = puntero + 1;
		}
		fclose(archivo);
		return 1;
	}
}

/*
int fscan(char filename[], int length, ...){
	FILE *file = fopen(filename,"a+");
	if(file == NULL){
		return 0;
	}
	else{	
		int i;
		char* argumento;
		va_list list;
		va_start(list, length);
		for(i = 0; i<length; i++){
			argumento = va_arg(list, char*);
			fprintf(file,"%s",argumento);
		}
		va_end(list);
		fclose(file);
		return 1;
	}
}
*/



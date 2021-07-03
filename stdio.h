#include <stdio.h>
#include <stdarg.h>

void print(char string[]){
	printf("%s",string);
}
void scan(char string[], int length){
	int point = 0;
	int ascii = 0;
	char buffer[length];
	fgets(buffer, (length+1), stdin);
	for(point=0; point<length; point++){
		ascii = buffer[point];
		if(ascii>=32 && ascii<=126){
			string[point] = ascii;
		}
		else{
			point = length;
			string[point] = 0;
		}
	}
}
int fscan(char filename[], char text[256][256], int* line){
	FILE *archivo = fopen(filename, "r");
	char caracter;
	int estado, x, y;
	x=0;
	y=0;	
	if(archivo == NULL){ 
		text[0][0] = 0;
		*line = 0;
		return -1;
	}
	else{
		while((caracter = fgetc(archivo)) != EOF){
			int byte = caracter;
			if(byte>=32 && byte<=126){
				caracter = byte;
				text[y][x] = caracter;
				x++;
			}
			else if(byte==10){
				caracter = byte; 
				text[y][x] = caracter;
				text[y][x+1] = 0;
				y++;
				x=0;
				text[y][x] = 0;
			}
		}
		fclose(archivo);
		*line = y;
		return 1;
	}
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
}*/


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



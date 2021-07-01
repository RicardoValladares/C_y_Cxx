#include <stdio.h>
#include <stdarg.h>

void print(char string[]){
	printf("%s",string);
}
void scan(char string[], int length){
	int point = 0;
	int size = 0;
	int ascii = 0;
	char buffer[length];
	fgets(buffer, length, stdin);
	for(point=0; point<length; point++){
		ascii = buffer[point];
		if(ascii>=32 && ascii<=126){
			string[size] = ascii;
			size = size + 1;
		}
		else{
			string[size] = 0;
			break;
		}
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



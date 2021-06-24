#include <stdio.h>
/* incluimos encabezados de librerias necesarias para el programa */
#include "library.h"		//libreria externa

/* funcion main con argumentos */
int main(int argc, char *argv[]){

	/*
	char* temp;
	int n1 = ctoi(temp = scan());
	int n2 = ctoi(temp = scan());
	int suma = n1 + n2;
	char* csuma = itoc(suma);
	print(itoc(n1));
	print("+");
	print(itoc(n2));
	print("=");
	print(csuma);
	*/
	
	char* temp = concat(2,"hola","mundo");
	print(temp);

	/* ejecutamos salida de la aplicacion con una pausa de 5 segundos 
	pausa(5);*/
	return 0;
}

#include <stdio.h>
/* incluimos encabezados de librerias necesarias para el programa */
#include "library.h"		//libreria externa

/* funcion main con argumentos */
int main(int argc, char *argv[]){

	/*char* cn1 = scan();
	int n1 = ctoi(cn1);
	char* cn2 = scan();
	int n2 = ctoi(cn2);
	int suma = n1 + n2;
	char* csuma = itoc(suma);
	print(csuma);*/

	char* concatenado = concat(2,"hola","mundo");

	/* ejecutamos salida de la aplicacion con una pausa de 5 segundos 
	pausa(5);*/
	return 0;
}

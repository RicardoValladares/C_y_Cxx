/* incluimos encabezados de librerias necesarias para el programa */
#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa
/* incluimos encabezados de codigos externos a usar en el programa */
#include "Persona.h" 		//$ gcc main.c Persona.c -o main.c

/* funcion main con argumentos */
int main(int argc, char *argv[]){
	
	/* declaracion de variables */
	int Edad, Estado, Ok, Error;
	char CEdad[10];
	Persona yo;
	
	/* incializacion de variables */
	Ok = 1;
	Error = 0;
	Persona_init(&yo);
	init_chars(CEdad,10);

	/* validamos si existen argumentos de apertura para la ejecucion */
	if(argc==2){
		Estado = Person_load(argv[1], &yo);
		if(Estado==1){
			printf("\n--------------------------------\n");
			Persona_show(yo);
			printf("--------------------------------\n");
			printf("Archivo cargado\n");
		}
		else{
			printf("Error al abrir archivo\n");
		}
	}

	/* si no hay argumentos validos creamos otra ejecucion */
	else{
		printf("Ingrese su Primer Nombre: ");
		scanf("%30s", yo.Nombre1);
		printf("Ingrese su Segundo Nombre: ");
		scanf("%30s", yo.Nombre2);
		printf("Ingrese su Primer Apellido: ");
		scanf("%30s", yo.Apellido1);
		printf("Ingrese su Segundo Apellido: ");
		scanf("%30s", yo.Apellido2);
		do{
			printf("Ingrese su Edad: ");
			scanf("%10s", CEdad);
			Estado = ctoi(CEdad, &yo.Edad);
		}while(Estado==Error);
		printf("\n\n--------------------------------\n");
		Persona_show(yo);
		printf("--------------------------------\n");
		Estado = Persona_save("Persona.txt",yo);
		if(Estado==Ok){
			printf("Archivo guardado\n");
		}
		else{
			printf("Error al guardar archivo\n");
		}
	}

	/* ejecutamos salida de la aplicacion con una pausa de 5 segundos */
	pausa(5);
	return 0;
}

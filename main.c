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
		if(Estado==Ok){
			//printf("\n--------------------------------\n");
			print("\n--------------------------------\n");
			Persona_show(yo);
			print("--------------------------------\n");
			print("Archivo cargado\n");
		}
		else{
			print("Error al abrir archivo\n");
		}
	}

	/* si no hay argumentos validos creamos otra ejecucion */
	else{
		print("Ingrese su Primer Nombre: ");
		scan(yo.Nombre1);
		print("Ingrese su Segundo Nombre: ");
		scan(yo.Nombre2);
		print("Ingrese su Primer Apellido: ");
		scan(yo.Apellido1);
		print("Ingrese su Segundo Apellido: ");
		scan(yo.Apellido2);
		do{
			print("Ingrese su Edad: ");
			scants(CEdad);
			printf("-%s-",CEdad);
			Estado = ctoi(CEdad, &yo.Edad);
		}while(Estado==Error);
		print("\n\n--------------------------------\n");
		Persona_show(yo);
		print("--------------------------------\n");
		Estado = Persona_save("Persona.txt",yo);
		if(Estado==Ok){
			print("Archivo guardado\n");
		}
		else{
			print("Error al guardar archivo\n");
		}
	}

	/* ejecutamos salida de la aplicacion con una pausa de 5 segundos */
	pausa(5);
	return 0;
}

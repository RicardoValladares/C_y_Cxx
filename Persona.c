#include "Persona.h" //header donde se encuentran los prototipos de Persona
//#include "library.h"
#include <stdio.h>


/* enunciamos los prototipos a usar de la libreria externa invocada en el main */
void inichars(char string[], int length);
int clchar(char ascii, char* character);
int ctoi(char string[10], int* integer);
void itoc(int integer, char string[10]);
void vprint(int length, ...);
int fprint(char filename[], int length, ...);


/* Inicializar Persona */
void init_Persona(Persona *person){
	person->Edad=0;
	inichars(person->Nombre1,30);
	inichars(person->Nombre2,30);
	inichars(person->Apellido1,30);
	inichars(person->Apellido2,30);
}

/* Mostrar Persona */
void show_Persona(Persona person){
	/*vprint(5, "Nombres: ", person.Nombre1, " ",person.Nombre2, "\n");
	vprint(5, "Apellidos: ", person.Apellido1, " ",person.Apellido2, "\n");
	char CEdad[10];
	inichars(CEdad,10);
	itoc(person.Edad, CEdad);
	vprint(3,"Edad: ",CEdad,"\n");*/
	printf("-%c-%d-\n",EOF,EOF);
}

/* Guardar Persona */
int save_Persona(char ruta[], Persona person){
	Estado estado;
	estado = fprint(ruta, 5, "Nombres: ",person.Nombre1, " ", person.Nombre2,"\n");
	estado = fprint(ruta, 5, "Apellidos: ",person.Apellido1, " ", person.Apellido2,"\n");
	char CEdad[10];
	inichars(CEdad,10);
	itoc(person.Edad, CEdad);
	estado = fprint(ruta, 3, "Edad: ",CEdad,"\n");
	return estado;
}

/* Cargar Persona */
int load_Persona(char ruta[], Persona *person){
	int i;
	Estado estado;
	char caracter, climpio;
	init_Persona(person);
	char linea1[71];
	char linea2[73];
	char linea3[17];
	int plinea1 = 0;
	int plinea2 = 0;
	int plinea3 = 0;
	inichars(linea1,71);
	inichars(linea2,73);
	inichars(linea3,17);
	int NewLine = 10;
	int Space = 32;
	int puntero = 0;
	int plineal = 0;
	int pespaciolineal = 0;
	char cedad[10];
	inichars(cedad,10);
	FILE *archivo = fopen(ruta, "r");
	if(archivo == NULL){ 
		return Error;
	}
	else{
		while((caracter = fgetc(archivo)) != EOF){ // char read("url",i)
			estado = clchar(caracter,&climpio);
			if(plineal==0){
				plinea1 = plinea1 + 1;
				linea1[puntero] = climpio;
			}
			if(plineal==1){
				plinea2 = plinea2 + 1;
				linea2[puntero] = climpio;
			}
			if(plineal==2){
				plinea3 = plinea3 + 1;
				linea3[puntero] = climpio;
			}
			if(caracter==NewLine){
				plineal = plineal + 1;
				puntero = 0;
			}
			puntero = puntero + 1;
		}
		fclose(archivo);
		if(plinea1<=9 || plinea2<=11 || plinea3<=6){
			return Error;
		}
		else{
			// de la linea 1 se toma Nombre1 y Nombre2
			pespaciolineal = 0;
			puntero = 0;
			for(i=8; i<=plinea1; i++){
				caracter = linea1[i];
				estado = clchar(caracter,&climpio);
				if(climpio == Space){
					if(i==8){
						pespaciolineal = 0;
					}
					else{
						pespaciolineal = pespaciolineal + 1;
					}
					puntero = 0;
				}
				//Nombre1
				if(pespaciolineal==0 && climpio!=Space){
					caracter = linea1[i];
					estado = clchar(caracter,&climpio);
					person->Nombre1[puntero] = climpio;
					puntero = puntero + 1;
				}
				//Nombre2
				if(pespaciolineal==1 && climpio!=Space){
					caracter = linea1[i];
					estado = clchar(caracter,&climpio);
					person->Nombre2[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			// de la linea 2 se toma Apellido1 y Apellido2
			pespaciolineal = 0;
			puntero = 0;
			for(i=11; i<=plinea2; i++){
				caracter = linea2[i];
				estado = clchar(caracter,&climpio);
				if(climpio == Space){
					if(i==11){
						pespaciolineal = 0;
					}
					else{
						pespaciolineal = pespaciolineal + 1;
					}
					puntero = 0;
				}
				//Apellido1
				if(pespaciolineal==0 && climpio!=Space){
					caracter = linea2[i];
					estado = clchar(caracter,&climpio);
					person->Apellido1[puntero] = climpio;
					puntero = puntero + 1;
				}
				//Apellido2
				if(pespaciolineal==1 && climpio!=Space){
					caracter = linea2[i];
					estado = clchar(caracter,&climpio);
					person->Apellido2[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			// de la linea 3 se toma la Edad
			puntero = 0;
			for(i=6; i<=plinea3; i++){
				caracter = linea3[i];
				estado = clchar(caracter,&climpio);
				if(climpio!=Space){
					caracter = linea3[i];
					estado = clchar(caracter,&climpio);
					cedad[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			estado = ctoi(cedad, &person->Edad);
		}
		return Ok;
	}
}

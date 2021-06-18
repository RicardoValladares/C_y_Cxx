#include "Persona.h" //header donde se encuentran los prototipos de Persona

/* enunciamos los prototipos a usar de la libreria externa invocada en el main */
void init_chars(char string[], int length);
int clean_char(char ascii, char* character);
int ctoi(char string[10], int* integer);


/* Inicializar Persona */
void Persona_init(Persona *person){
	person->Edad=0;
	init_chars(person->Nombre1,30);
	init_chars(person->Nombre2,30);
	init_chars(person->Apellido1,30);
	init_chars(person->Apellido2,30);
}

/* Mostrar Persona */
void Persona_show(Persona person){
	printf("Nombres: %s %s\n",person.Nombre1, person.Nombre2);
	printf("Apellidos: %s %s\n",person.Apellido1, person.Apellido2);
	printf("Edad: %d\n",person.Edad);
}

/* Guardar Persona */
int Persona_save(char ruta[], Persona person){
	FILE *archivo = fopen(ruta,"w");
	if(archivo == NULL){ 
		return Error;
	}
	else{	
		fprintf(archivo,"Nombres: %s %s\n",person.Nombre1, person.Nombre2);
		fprintf(archivo,"Apellidos: %s %s\n",person.Apellido1, person.Apellido2);
		fprintf(archivo,"Edad: %d\n",person.Edad);
		fclose(archivo);
		return Ok;
	}
}

/* Cargar Persona */
int Person_load(char ruta[], Persona *person){
	int i;
	Estado estado;
	char caracter, climpio;
	Persona_init(person);
	char linea1[71];
	char linea2[73];
	char linea3[17];
	int plinea1 = 0;
	int plinea2 = 0;
	int plinea3 = 0;
	init_chars(linea1,71);
	init_chars(linea2,73);
	init_chars(linea3,17);
	int NewLine = 10;
	int Space = 32;
	int puntero = 0;
	int plineal = 0;
	int pespacion = 0;
	char cedad[10];
	init_chars(cedad,10);
	FILE *archivo = fopen(ruta, "r");
	if(archivo == NULL){ 
		return Error;
	}
	else{
		while((caracter = fgetc(archivo)) != EOF){
			estado = clean_char(caracter,&climpio);
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
			pespacion = 0;
			puntero = 0;
			for(i=8; i<=plinea1; i++){
				caracter = linea1[i];
				estado = clean_char(caracter,&climpio);
				if(climpio == Space){
					if(i==8){
						pespacion = 0;
					}
					else{
						pespacion = pespacion + 1;
					}
					puntero = 0;
				}
				if(pespacion==0 && climpio!=Space){
					caracter = linea1[i];
					estado = clean_char(caracter,&climpio);
					person->Nombre1[puntero] = climpio;
					puntero = puntero + 1;
				}
				if(pespacion==1 && climpio!=Space){
					caracter = linea1[i];
					estado = clean_char(caracter,&climpio);
					person->Nombre2[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			// de la linea 2 se toma Apellido1 y Apellido2
			pespacion = 0;
			puntero = 0;
			for(i=11; i<=plinea2; i++){
				caracter = linea2[i];
				estado = clean_char(caracter,&climpio);
				if(climpio == Space){
					if(i==11){
						pespacion = 0;
					}
					else{
						pespacion = pespacion + 1;
					}
					puntero = 0;
				}
				if(pespacion==0 && climpio!=Space){
					caracter = linea2[i];
					estado = clean_char(caracter,&climpio);
					person->Apellido1[puntero] = climpio;
					puntero = puntero + 1;
				}
				if(pespacion==1 && climpio!=Space){
					caracter = linea2[i];
					estado = clean_char(caracter,&climpio);
					person->Apellido2[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			// de la linea 3 se toma la Edad
			puntero = 0;
			for(i=6; i<=plinea3; i++){
				caracter = linea3[i];
				estado = clean_char(caracter,&climpio);
				if(climpio!=Space){
					caracter = linea3[i];
					estado = clean_char(caracter,&climpio);
					cedad[puntero] = climpio;
					puntero = puntero + 1;
				}
			}
			estado = ctoi(cedad, &person->Edad);
		}
		return Ok;
	}
}

#include "library.h"

#define Error -1 
#define Ok 1
#define NewLine 10
#define Space 32
#define null 0

typedef struct{
   char Nombre1[30];
   char Nombre2[30];
   char Apellido1[30];
   char Apellido2[30];
   int Edad;
} Persona;

void Mostrar_Persona(Persona persona);
int Guardar_Persona(char archivo[], Persona persona);
int Abrir_Persona(char archivo[], Persona *persona);

int main(int argc, char *argv[]){
   Persona yo;
   int Estado;
   if(argc!=2){
      clear();
      print("Ingrese su Primer Nombre: ");
      scan(yo.Nombre1, 30);
      print("Ingrese su Segundo Nombre: ");
      scan(yo.Nombre2, 30);
      print("Ingrese su Primer Apellido: ");
      scan(yo.Apellido1, 30);
      print("Ingrese su Segundo Apellido: ");
      scan(yo.Apellido2, 30);
      do{
         char edad[10];
         print("Ingrese su Edad: ");
         scan(edad, 10);
         Estado = ctoi(edad, &yo.Edad);
      }while(Estado==Error);
      Estado = Guardar_Persona("Persona.txt", yo);
      if(Estado==Error){
         return 0;
      }
   }
   else{
      clear();
      Estado = Abrir_Persona(argv[1], &yo);
      if(Estado==Error){
         return 0;
      }
   }
   Mostrar_Persona(yo);
   pausa(5);
   return 0;
}

/********************************************/
/*   out var in c function(&var);           */
/*   function(*var){ *var = OK; }           */
/*                                          */
/*   out array in c function(array[]);      */
/*   function(array[]){ array[0] = OK; }    */
/********************************************/

void Mostrar_Persona(Persona persona){
   char edad[10];
   print("\n--------------------------------\n");
   print("Nombres: ");
   print(persona.Nombre1);
   print(" ");
   print(persona.Nombre2);
   print("\nApellidos: ");
   print(persona.Apellido1);
   print(" ");
   print(persona.Apellido2);
   print("\nEdad: ");
   itoc(persona.Edad,edad);
   print(edad);
   print("\n--------------------------------\n");
}

int Guardar_Persona(char archivo[], Persona persona){
   char edad[10];
   int estado = newtxt(archivo);
   if(estado==Error){
      print("Error al guardar el archivo\n");
      return Error;
   }
   printxt(archivo, persona.Nombre1);
   printxt(archivo, " ");
   printxt(archivo, persona.Nombre2);
   printxt(archivo, " \n");
   printxt(archivo, persona.Apellido1);
   printxt(archivo, " ");
   printxt(archivo, persona.Apellido2);
   printxt(archivo, " \n");
   itoc(persona.Edad, edad);
   printxt(archivo, edad);
   printxt(archivo, " \n");
   print("Archivo guardado\n");
   return Ok;
}

int Abrir_Persona(char archivo[], Persona *persona){
   int lineas, linea, caracter, estado;
   char texto[100][100];
   int token = 0;
   int x = 0;
   char edad[10] = { null, null, null, null, null, null, null, null, null, null };
   persona->Nombre1[0] = null;
   persona->Nombre2[0] = null;
   persona->Apellido1[0] = null;
   persona->Apellido2[0] = null;
   persona->Edad = null;
   estado = scantxt(archivo, texto, &lineas);
   if(lineas<3 || estado==Error){
      print("Error al abrir el archivo\n");
      return Error;
   }
   for(linea=0; linea<=lineas; linea++){
      for(caracter=0; caracter<100; caracter++){
         int ascii = texto[linea][caracter];
         if(ascii==null || ascii==NewLine){
            caracter = 100;
         }
         else{
            if(ascii==Space){
               token++;
               x = 0;
            }
            if(token==0 && ascii!=Space){
               persona->Nombre1[x++] = ascii;
               persona->Nombre1[x] = null;
            }
            if(token==1 && ascii!=Space){
               persona->Nombre2[x++] = ascii;
               persona->Nombre2[x] = null;
            }
            if(token==2 && ascii!=Space){
               persona->Apellido1[x++] = ascii;
               persona->Apellido1[x] = null;
            }
            if(token==3 && ascii!=Space){
               persona->Apellido2[x++] = ascii;
               persona->Apellido2[x] = null;
            }
            if(token==4 && ascii!=Space){
               edad[x++] = ascii;
               edad[x] = null;
            }
         }
      }
   }
   estado = ctoi(edad, &persona->Edad);
   if(estado==Error){
      print("Error al abrir el archivo\n");
      return Error;
   }
   else{
      return Ok;
   }
}

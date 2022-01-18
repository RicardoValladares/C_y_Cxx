# Libreria personalizada para C
Compatible con los compiladores: Turbo C, unix, GNU y xcode.
El proyecto viene preconfigurado para funcionar con Visual Studio Code. 
En caso no uses el editor de codigo Visual Studio Code, puedes usar los siguientes comandos para compilar y ejecutar de manera rapida en Windows y Linux usando GCC.

Linux:
```bash
  make compile
  make run
  make runarg
```


Windows:
```batch
  make compile
  make run
  make runarg
```



Codigo de Ejemplo usado esta libreria:

## main: 
```c
#include "library.h" 
 
#define Error -1 
#define Ok 1 
 
int main(int argc, char *argv[]){ 
   int estado, linea; 
   char texto[100][100]; 
   int lineas = 0; 
   if(argc!=2){ 
      print("Requiere un argmento\n"); 
   } 
   else{ 
      clear(); 
      estado = scantxt(argv[1], texto, &lineas); 
      if(lineas<2 || estado==Error){ 
         print("Error al abrir el archivo: ");  
         print(argv[1]); 
         return Error; 
      } 
      for(linea=0; linea<=lineas; linea++){ 
         print(texto[linea]); 
         print("\n"); 
      } 
      pausa(5); 
   } 
   return Ok; 
} 
 
```


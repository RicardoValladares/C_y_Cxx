//#include <string.h>
#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa

int main(int argc, char *argv[]){
	char c[256]; 
	int estado = concat(c,"HOLA \n","Ricardo");
	if(estado==-1){
			print("ERROR\n");
		}
		else{
			print(c);
		}
	return 0;

	/*int n1, n2, suma;
	char cn1[10], cn2[10], csuma[10];
	scan(cn1,10);
	scan(cn2,10);
	
	int estado = ctoi(cn1,&n1);
	if(estado==-1){
		print("ERROR1\n");
		return 0;
	}
	printf("\n%d\n",n1);
	estado = ctoi(cn2,&n2);
	if(estado==-1){
		print("ERROR2\n");
		return 0;
	}
	printf("%d\n\n",n2);
	suma = n1 + n2;
	estado = itoc(suma,csuma);
	printf("%d %s",suma,csuma);*/

	

	/*int num = -5230;
	char cars[10];
	int estado = itoc(num,cars);
	if(estado==-1){
		printf("ERROR %d\n",num);
	}
	else{
		printf("%d\n",num);
	}*/

	
	/*char a[] = "hola ";
	char b[] = "0123456789";
	char c[256];

	int estado = concat(c,a,b);
	if(estado==-1){
			print("ERROR\n");
		}
		else{
			print(c);
		}
	return 0;*/

	/*char textil[256][256];
	char texti[256][256];
	int line, lin, a;
	int estado = fscan("Persona.txt",textil, &line);
	estado = fscan("library.h",texti, &lin);
	
	for(a=0;a<=line;a++){
		print(textil[a]);
	}
	for(a=0;a<=lin;a++){
		print(texti[a]);
	}*/
	
}

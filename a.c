//#include <string.h>
#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa

int main(int argc, char *argv[]){
	/*int num = -5230;
	char cars[10];
	int estado = itoc(num,cars);
	if(estado==-1){
		printf("ERROR %d\n",num);
	}
	else{
		printf("%d\n",num);
	}*/

	
	char a[] = "hola ";
	char b[] = "0123456789";
	char c[256];

	int estado = concat(c,a,b);
	if(estado==-1){
			print("ERROR\n");
		}
		else{
			print(c);
		}
	return 0;

	//				(pf, ts)
	//s + s = 		0, 2
	
	//NULL + 4353 =	-1, 3
	//NULL + NULL = -1, -1
	// s + NULL =	0, -1
}

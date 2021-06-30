//#include <string.h>
#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa

int main(int argc, char *argv[]){
	/*int num;
	char cars[10] = "9999999999";
	int estado = ctoi(cars,&num);
	if(estado==-1){
		printf("ERROR %d\n",num);
	}
	else{
		printf("%d\n",num);
	}*/
	char a[] = "HOLA";
	char b[] = "0123456789";
	char c[256];

	concat(c,a,b);
	printf("-%s-",c);
	return 0;
}

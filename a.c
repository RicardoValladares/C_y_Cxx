#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa

int main(int argc, char *argv[]){
	int num = -999999999;
	char cars[10];
	int estado = itoc(num,cars);
	if(estado==-1){
		printf("ERROR %s\n",cars);
	}
	else{
		printf("%s\n",cars);
	}
	return 0;
}


#include <stdio.h> 		//libreria del compilador
#include "library.h"		//libreria externa

int main(int argc, char *argv[]){
	int num;
	char cars[10] = "253";
	int estado = ctoi(cars,&num);
	if(estado==0){
		printf("ERROR %d\n",num);
	}
	else{
		printf("%d\n",num);
	}
	return 0;
}

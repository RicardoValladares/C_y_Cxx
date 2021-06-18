#include <unistd.h>
#include <stdio.h>

void pausa(int segundos);

void pausa(int segundos){
	printf("Pausado... %d",segundos);
	do{
		segundos--;
		sleep(1); 
		printf(" %d",segundos);
	}while(segundos>0);
	printf("\n");
}

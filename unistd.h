#include <unistd.h>
#include <stdio.h>

void pausa(int seconds){
	printf("Pausado... %d", seconds);
	do{
		seconds--;
		sleep(1); 
		printf(" %d", seconds);
	}while(seconds>0);
	printf("\n");
}

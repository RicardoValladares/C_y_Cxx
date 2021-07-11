#include <unistd.h> 
#include <stdio.h> 
 
void pausa(int seconds){ 
   fprintf(stderr,"Pausado... %d", seconds); 
   do{ 
      seconds--; 
      sleep(1); 
      fprintf(stderr," %d", seconds); 
   }while(seconds>0); 
   fprintf(stderr,"\n"); 
} 
 

#include <stdio.h> 
#ifdef __TURBOC__ 
#include <dos.h> 
#else 
#include <unistd.h> 
#endif 
 
void pausa(int seconds){ 
   fprintf(stderr,"Pausado... %d", seconds); 
   do{
      seconds--; 
      #ifdef __TURBOC__
      delay(1000); 
      #else
      sleep(1); 
      #endif
      fprintf(stderr," %d", seconds); 
   }while(seconds>0); 
   fprintf(stderr,"\n"); 
} 
 

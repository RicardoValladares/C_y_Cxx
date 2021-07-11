#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 

int global = 1;

/*thread function definition*/
void* threadFunction(void* args)
{
    int seconds = 1000;
    fprintf(stderr,"Runner... %d", seconds); 
   do{ 
      seconds--; 
      sleep(1); 
      fprintf(stderr,"\b %d", seconds); 
   }while(global); 
   //printf("\n"); 
}
int main()
{
    /*creating thread id*/
    pthread_t id;
    int ret;
    
    /*creating thread*/
    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    if(ret==0){
        fprintf(stderr,"Hilo Creado.\n");
    }
    else{
        fprintf(stderr,"Hilo no Creado.\n");
        return 0; /*return from main*/
    }
    
    /*while(1)
    {
        printf("I am main function.\n");      
    }*/

        char  line[256], character;                              
       int   c;                                                
       c = 0;                                                  
       do                                                      
       {                                                       
           character = getchar();                              
           line[c]   = character;                              
           c++;                                                
           fprintf(stderr,"\b"); 
       }                                                       
       while(character != '\n');  
       global = 0;                              
       c = c - 1;                                              
       line[c] = '\0';                                         
       fprintf(stderr,"%s\n", line);           


    
    return 0;
}


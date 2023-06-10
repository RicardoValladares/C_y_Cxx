#include "libreria.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdarg.h> 
#ifdef __TURBOC__ 
#include <dos.h> 
#else 
#include <unistd.h> 
#endif 

#ifdef __TURBOC__ 
void clear(){ 
   system("cls"); 
} 
#else 
#ifdef _WIN32 
void clear(){ 
   system("cls"); 
} 
#else 
void clear(){ 
   system("clear"); 
} 
#endif 
#endif 
 
void print(char string[]){ 
   fprintf(stderr,"%s",string); 
} 
 
void scan(char string[], int length){ 
   char buffer[100]; 
   int point = 0; 
   int ascii = 0; 
   fgets(buffer, (length+1), stdin); 
   for(point=0; point<length; point++){ 
      ascii = buffer[point]; 
      if(ascii>=32 && ascii<=126){ 
         string[point] = ascii; 
      } 
      else{ 
         string[point] = 0; 
         point = length; 
      } 
   } 
} 
 
int scantxt(char filename[], char text[100][100], int* line){ 
   char ascii; 
   int x = 0; 
   int y = 0; 
   FILE *file = fopen(filename, "r"); 
   if(file==NULL){ 
      text[0][0] = 0; 
      *line = 0; 
      return -1; 
   } 
   while(((ascii=fgetc(file))!=EOF) && (x<100 && y<100)){ 
      text[y][x++] = ascii>=32 && ascii<=126 ? ascii : 0; 
      if(ascii==10){ 
         x = 0; 
         text[++y][x] = 0; 
      } 
   } 
   fclose(file); 
   *line = y; 
   return 1; 
} 
 
int newtxt(char filename[]){ 
   FILE *file = fopen(filename,"w"); 
   if(file == NULL){ 
      return -1; 
   } 
   fclose(file); 
   return 1; 
} 
 
int printxt(char filename[], char string[]){ 
   FILE *file = fopen(filename,"a+"); 
   if(file == NULL){ 
      return -1; 
   } 
   fprintf(file,"%s",string); 
   fclose(file); 
   return 1; 
} 
 
int atoc(int ascii, char* character){ 
   if(ascii>=32 && ascii<=126){ 
      *character = ascii; 
      return 1; 
   } 
   *character = 0; 
   return -1; 
} 
 
int ctoi(char string[], int* integer){  
   int unitdecimal[10]; 
   int ascii, limit, decimal; 
   int point = 0; 
   int length = 0; 
   int digits = 0; 
   int overflow = 0; 
   *integer = 0; 
   unitdecimal[0] = 1; 
   for(decimal=1; decimal<9; decimal++){ 
      unitdecimal[decimal] = decimal * 10; 
   } 
   if(string[0]==45 && (string[1]<=57 && string[1]>=48)){ 
      limit = 1; 
   } 
   else if(string[0]<=57 && string[0]>=48){ 
      limit = 0; 
   } 
   else{ 
      return -1; 
   } 
   do{ 
      ascii = string[point]; 
      point = (ascii==45 || (ascii<=57 && ascii>=48)) ? point+1 : point; 
      if(ascii!=45 && (ascii>57 || ascii<48)){ 
         length = point; 
      } 
   }while(length==0); 
   if(length>10){ 
      return -1; 
   } 
   for(point=(length-1); point>=limit; point--){ 
      ascii = string[point]; 
      if(ascii<=57 && ascii>=48){ 
         *integer = (*integer) + ((ascii - '0') * unitdecimal[digits++]); 
      } 
      if(*integer>1400000000){ 
         overflow = 1; 
         point = -1; 
      } 
   } 
   if(overflow==1 || digits==0){ 
      *integer = 0; 
      return -1; 
   } 
   if(string[0]==45){ 
      *integer = 0 - *integer;	 
   } 
   return 1; 
} 
 
int itoc(int integer, char string[10]){ 
   int limit = 0; 
   int digit = 0; 
   int point = 0; 
   int length = 0; 
   char buffer[10]; 
   if(integer<0){ 
      string[length] = '-'; 
      length = 1; 
      integer *= (-1); 
   } 
   do{ 
      limit++; 
      buffer[point] = (integer % 10) + '0'; 
      integer /= 10; 
      point++; 
   }while(integer); 
   limit--; 
   for(point=0; point<10; point++){ 
      digit = buffer[limit-point] - '0'; 
      string[length] = (digit<=9 && digit>=0) ? digit + '0' : 0; 
      length++;	
   } 
   return 1; 
} 
 
int concat(char string[], char *first, ...){ 
   int point; 
   char character; 
   char *token; 
   int length = 0; 
   int lengthfirst = 0; 
   int isfirst = 1; 
   va_list args; 
   va_start(args, first); 
   token = first; 
   while(token){ 
      point = 0; 
      character = token[point]; 
      while((character>=32 && character<=126) || (character==10)){ 
         if(isfirst==1){ 
            lengthfirst++; 
         } 
         string[length] = character; 
         point++; 
         character = token[point]; 
         length++; 
      } 
      isfirst = 0; 
      token = va_arg(args, char*); 
   } 
   length--; 
   lengthfirst--; 
   va_end(args); 
   for(point=0; point<=lengthfirst; point++){ 
      if(string[length-point] == first[lengthfirst-point]){ 
         string[length-point] = 0; 
      } 
      else if(string[length-point]<=33 || string[length-point]>=126){ 
         string[length-point] = 0; 
      } 
   } 
   if(lengthfirst<0 || length<0){ 
      string[0] = 0; 
      return -1; 
   } 
   return 1; 
} 
 
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
 
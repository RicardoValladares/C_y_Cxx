#include <stdio.h> 
#include <stdlib.h> 
 
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
 

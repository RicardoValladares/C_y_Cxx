#include <stdio.h> 
 
void print(char string[]){ 
   printf("%s",string); 
} 
 
void scan(char string[], int length){ 
   int point = 0; 
   int ascii = 0; 
   char buffer[length]; 
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
 
int scantxt(char filename[], char text[256][256], int* line){ 
   FILE *file = fopen(filename, "r"); 
   char ascii; 
   int x, y; 
   x = 0; 
   y = 0; 
   if(file==NULL){ 
      text[0][0] = 0; 
      *line = 0; 
      return -1; 
   } 
   while((ascii=fgetc(file)) != EOF){ 
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
 
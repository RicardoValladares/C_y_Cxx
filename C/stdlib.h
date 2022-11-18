#include <stdarg.h> 
 
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
 

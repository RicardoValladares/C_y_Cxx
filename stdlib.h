
int clean_char(char ascii, char* character){
	int byte = ascii;
	if(byte>=33 && byte<=126){
		*character = byte;
		return 1;
	}
	else{
		*character = 32;
		return 0;
	}
}

int ctoi(char string[10], int* integer){  
	int estado;
	int counter = 0;
	int byte, point;
		int sucecion[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
		int psucecion=0;
		for(point=0; point<10; point++) {
			byte = string[9-point];
			if(byte<=57 && byte>=48){
				byte = string[9-point] - '0';
				*integer = *integer + (byte *sucecion[psucecion++]);
				counter++;
			}
		}
		if(string[0]==45 && *integer!=0){
			*integer = 0 - *integer;
		}
		if(counter>0){
			return 1;
		}
		else{
			*integer = 0;
			return 0;
		}
}









/*

char* itoc(int integer){
	static char string[10];
	char buffer[10];
	int byte; 
	int point = 0;
	int psucecion = 0;
	if(integer<0){ string[0] = '-'; }
	if(integer<0){ psucecion=1; integer = abs(integer); }
	do{
		byte = integer % 10;
		buffer[point] = byte + '0';
		integer = integer / 10;
		point = point + 1;
	}while(integer!=0);
	for(point=0; point<10; point++) {
		byte = buffer[9-point] - '0';
		if(byte<=9 && byte>=0){
			string[psucecion] = byte + '0';
			psucecion++;
		}	
	}
	return string;
}


void concat(char string[],int length, ...){
	char* argumento;
	int larg=0;
	int parg;
	int point;
	char byte;
	va_list list;
	va_start(list, length);
	//static char string[256];
	for(parg=0; parg<length; parg++){
		argumento = va_arg(list, char*);
		point = 0;
		byte = argumento[0];
		while(byte>=32 && byte<=126){
			string[larg] = byte;
			point = point+1;
			byte = argumento[point];
			larg++;
		}
	}
	va_end(list);
	//printf("%d -%s-\n",larg,string);
}



*/

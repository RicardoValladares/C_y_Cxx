void init_chars(char string[], int length);
int copy_chars(char INstring[], char OUTstring[], int OUTlength);
int clean_char(char ascii, char* character);
int ctoi(char string[10], int* integer);

void init_chars(char string[], int length){
	int puntero;
	for(puntero=0; puntero<length; puntero++){
		string[puntero] = 0;
	}
}

int copy_chars(char INstring[], char OUTstring[], int OUTlength){
	int puntero, byte; 
	int errores = 0;
	for(puntero=0; puntero<OUTlength; puntero++){
		byte = INstring[puntero];
		if(byte>=33 && byte<=126){
			OUTstring[puntero] = INstring[puntero];
		}
		else{
			OUTstring[puntero] = 0;
			errores = errores + 1;
		}
	}
	if(errores>0){
		return 0;
	}
	else{
		return 1;
	}
}

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
	int sucecion[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	int byte, nextbyte, puntero;
	int psucecion=0;
	int numero=0;
	for(puntero=0; puntero<10; puntero++) {
		byte = string[9-puntero];
		nextbyte = puntero==0 ? 0 : string[9-(puntero-1)];
		if(byte<=57 && byte>=48){
			byte = string[9-puntero] - '0';
			numero = numero + (byte *sucecion[psucecion++]);
			estado = 1;
		}
		else if(byte==45){
			estado = 1;
			break;
		}
		else if((byte>57 || byte<48) && byte!=0 && byte!=45){
			numero = 0;
			estado = 0;
			break;
		}
		else if(byte==0 && nextbyte!=0){
			numero = 0;
			estado = 0;
			break;
		}
	}
	if(string[0]==45 && numero!=0){
		numero = 0 - numero;
	}
	else{
		numero = numero;
	}
	*integer = numero;
	return estado;
}

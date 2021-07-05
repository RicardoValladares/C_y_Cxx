compile: 
	clear 
	gcc main.c -o main.bin 
	i686-w64-mingw32-gcc main.c Persona.c -o main.exe 
 
run: 
	clear 
	./main.bin 
	

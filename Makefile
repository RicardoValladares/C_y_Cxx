main.bin: main.c
	gcc main.c Persona.c -o main.bin

all:
	gcc main.c Persona.c -o main.bin
	i686-w64-mingw32-gcc main.c Persona.c -o main.exe

clean:
	rm main.bin
	rm main.exe

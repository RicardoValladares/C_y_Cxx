main.bin: main.c
	gcc main.c Persona.c -o main.bin

all:
	gcc main.c Persona.c -o main.bin

clean:
	rm main.bin

compile:
	clear
	gcc a.c -o a.bin

run:
	clear
	./a.bin


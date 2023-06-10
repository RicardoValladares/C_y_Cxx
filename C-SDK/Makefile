UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/libreria.o ./CODE/libreria.c
	gcc -shared -o ./SDK/liblibreria.so ./CODE/libreria.o
	cp ./CODE/libreria.h ./SDK/libreria.h
	rm ./CODE/libreria.o
	# Compilar Programa
	cp ./SDK/liblibreria.so ./Release/liblibreria.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibreria  -o ./Release/main.bin
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.bin 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.bin  ./Persona.txt

endif
ifeq ($(UNAME), Darwin)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/libreria.o ./CODE/libreria.c
	gcc -shared -o ./SDK/liblibreria.so ./CODE/libreria.o
	cp ./CODE/libreria.h ./SDK/libreria.h
	rm ./CODE/libreria.o
	# Compilar Programa
	cp ./SDK/liblibreria.so ./Release/liblibreria.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibreria  -o ./Release/main.app
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.app 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.app Persona.txt

endif
ifeq ($(UNAME), FreeBSD)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/libreria.o ./CODE/libreria.c
	gcc -shared -o ./SDK/liblibreria.so ./CODE/libreria.o
	cp ./CODE/libreria.h ./SDK/libreria.h
	rm ./CODE/libreria.o
	# Compilar Programa
	cp ./SDK/liblibreria.so ./Release/liblibreria.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibreria  -o ./Release/main.bsd
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.bsd 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.bsd Persona.txt

endif



UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/library.o ./CODE/library.c
	gcc -shared -o ./SDK/liblibrary.so ./CODE/library.o
	cp ./CODE/library.h ./SDK/library.h
	rm ./CODE/library.o
	# Compilar Programa
	cp ./SDK/liblibrary.so ./Release/liblibrary.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibrary  -o ./Release/main.bin
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.bin 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.bin  ./Persona.txt

endif
ifeq ($(UNAME), Darwin)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/library.o ./CODE/library.c
	gcc -shared -o ./SDK/liblibrary.so ./CODE/library.o
	cp ./CODE/library.h ./SDK/library.h
	rm ./CODE/library.o
	# Compilar Programa
	cp ./SDK/liblibrary.so ./Release/liblibrary.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibrary  -o ./Release/main.app
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.app 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.app Persona.txt

endif
ifeq ($(UNAME), FreeBSD)

compile:
	# Compilar SDK
	gcc -c -Wall -Werror -fpic -o ./CODE/library.o ./CODE/library.c
	gcc -shared -o ./SDK/liblibrary.so ./CODE/library.o
	cp ./CODE/library.h ./SDK/library.h
	rm ./CODE/library.o
	# Compilar Programa
	cp ./SDK/liblibrary.so ./Release/liblibrary.so
	gcc -Wall -I./SDK   -c ./main.c -o ./main.o 
	gcc -L./SDK   main.o  -llibrary  -o ./Release/main.bsd
	rm ./main.o 

run:
	LD_LIBRARY_PATH="./Release" ./Release/main.bsd 

runarg:
	LD_LIBRARY_PATH="./Release" ./Release/main.bsd Persona.txt

endif



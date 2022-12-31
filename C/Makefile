UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

compile:
	gcc main.c -o ./dist/Linux.bin

run:
	./dist/Linux.bin

runarg:
	./dist/Linux.bin Persona.txt

endif
ifeq ($(UNAME), Darwin)

compile:
	gcc main.c -o ./dist/MacOS.app.bin

run:
	./dist/MacOS.app.bin

runarg:
	./dist/MacOS.app.bin Persona.txt

endif
ifeq ($(UNAME), FreeBSD)

compile:
	gcc main.c -o ./dist/BSD.bin

run:
	./dist/BSD.bin

runarg:
	./dist/BSD.bin Persona.txt

endif



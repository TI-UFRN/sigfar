execute: all
	rm *.o
	clear
	./program.exe

all: _build

_build: _compile
	g++ main.o encrypt.o print.o mainMenuFunctions.o files.o loggedState.o user.o medicine.o cart.o -o program.exe
_compile: _clean
	g++ -c main.cpp functions/implementations/encrypt.cpp functions/implementations/print.cpp functions/implementations/mainMenuFunctions.cpp functions/implementations/loggedState.cpp functions/implementations/files.cpp entities/implementations/user.cpp entities/implementations/medicine.cpp entities/implementations/cart.cpp 
_clean:
	touch fake.o fake.exe
	rm *.o *.exe
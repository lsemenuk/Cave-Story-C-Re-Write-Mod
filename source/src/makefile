
cavestory: main.o Graphics.o Game.o Input.o
	g++ main.o Graphics.o Game.o Input.o -o cavestory -framework SDL2


main.o: main.cc
	g++ -c main.cc 

Graphics.o: Graphics.cc Graphics.h
	g++ -c Graphics.cc

Game.o: Game.cc Game.h
	g++ -c Game.cc

Input.o: Input.cc Input.h
	g++ -c Input.cc

clean:
	rm *.o output

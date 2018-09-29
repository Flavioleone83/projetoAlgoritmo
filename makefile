all: Main.o
	g++ Main.o -o index.exe

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm *.exe

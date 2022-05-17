make: main.o Drawer.o Picross.o
	$(CXX) main.o Drawer.o Picross.o -o picross-solver -lsfml-graphics -lsfml-window -lsfml-system

Drawer.o: Drawer.cpp Drawer.h
	$(CXX) -c Drawer.cpp Drawer.h 

Picross.o: Picross.cpp Picross.h
	$(CXX) -c Picross.cpp Picross.h 

main.o: main.cpp
	$(CXX) -c main.cpp 


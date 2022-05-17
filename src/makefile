make: main.o Drawer.o
	$(CXX) main.o Drawer.o -o picross-solver -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CXX) -c main.cpp 

Drawer.o: Drawer.cpp Drawer.h
	$(CXX) -c Drawer.cpp Drawer.h 
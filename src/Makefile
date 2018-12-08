CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic 
INCLUDES=-I/usr/include/
LDFLAGS=-L/usr/include/ -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp game.cpp map.cpp player.cpp gamemode.cpp guiwindow.cpp startmenu.cpp gamegui.cpp mapmenu.cpp
OBJECTS=main.o tilematching.o game.o map.o player.o gamemode.o guiwindow.o startmenu.o gamegui.o mapmenu.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cpp.o:
	$(CC) $(CPPFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main

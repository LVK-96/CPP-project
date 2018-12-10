CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
INCLUDES=-I/usr/include/
LDFLAGS=-L/usr/include/ -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp game.cpp map.cpp player.cpp gamemode.cpp guiwindow.cpp startmenu.cpp gamegui.cpp mapmenu.cpp scoregui.cpp mapsize.cpp mapeditor.cpp
OBJECTS=main.o game.o map.o player.o gamemode.o guiwindow.o startmenu.o gamegui.o mapmenu.o scoregui.o mapsize.o mapeditor.o
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


CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic
INCLUDES=-I/usr/include/
<<<<<<< HEAD
LDFLAGS=-L/usr/include/ -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp game.cpp map.cpp player.cpp gamemode.cpp guiwindow.cpp startmenu.cpp gamegui.cpp mapmenu.cpp scoregui.cpp mapsize.cpp mapeditor.cpp savemap.cpp
OBJECTS=main.o game.o map.o player.o gamemode.o guiwindow.o startmenu.o gamegui.o mapmenu.o scoregui.o mapsize.o mapeditor.o savemap.o
=======
LDFLAGS=-L/usr/include/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
SOURCES=main.cpp game.cpp map.cpp player.cpp gamemode.cpp guiwindow.cpp startmenu.cpp gamegui.cpp scoregui.cpp mapsize.cpp mapeditor.cpp mapmenu.cpp
OBJECTS=main.o game.o map.o player.o gamemode.o guiwindow.o startmenu.o gamegui.o scoregui.o mapsize.o mapeditor.o mapmenu.o
>>>>>>> d94f7ed68a6d7e6acbc1c58f13ffba30dccdf60d
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


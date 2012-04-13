CC=g++
CFLAGS= -c -Wall -ansi -pedantic
LDFLAGS= 
SOURCES= src/main.cpp src/sword.cpp src/shuriken.cpp src/samurai.cpp src/factory.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=samurai
LIBS= -lboost_thread

all: $(SOURCES) $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o bin/$@

.cpp.o:
	$(CC) $(CFLAGS)  $< -o $@

clean:
	rm -f src/*.o bin/$(EXECUTABLE)
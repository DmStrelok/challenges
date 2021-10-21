.PHONY: all clean

CC = g++ -std=c++17
CFLAGS = -c -g -Wall -Wuninitialized
LDFLAGS =
OFLAGS =
LIBS =
SOURCES = main.cpp poisonous-plants/solution.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main
TARGET = EXECUTABLE

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OFLAGS) $(LIBS) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(OFLAGS) $(LIBS) $(CFLAGS) $< -o $@

clean:
	rm -rf *.a $(EXECUTABLE) $(OBJECTS)

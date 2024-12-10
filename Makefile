CC = g++
CPPFLAGS = -Wall

# add each module when ready to use
OBJECTS = build/parser.o build/token.o build/lexer.o

test: tests/expressions.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJECTS): build/%.o: src/%.cpp build
	$(CC) -c $(CPPFLAGS) $< -o $@

build:
	mkdir build

clean:
	rm -rf build test

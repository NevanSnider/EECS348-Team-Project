CC = g++
# CPPFLAGS = -Wall

# add each module when ready to use
OBJECTS = build/parser.o build/token.o build/lexer.o build/evaluator.o

cli: src/ui.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

test: tests/cases.cpp tests/testing.cpp $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@
	
$(OBJECTS): build/%.o: src/%.cpp build
	$(CC) -c $(CPPFLAGS) $< -o $@

build:
	mkdir build

clean:
	rm -rf build test cli

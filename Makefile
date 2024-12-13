CC = g++
# CPPFLAGS = -Wall

# Module object files
OBJECTS = build/parser.o build/token.o build/lexer.o build/evaluator.o

# Build the calculator CLI
cli: src/ui.cpp $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@

# Build the test executable
test: tests/cases.cpp tests/testing.cpp $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@

# Build each module
$(OBJECTS): build/%.o: src/%.cpp build
	@$(CC) -c $(CPPFLAGS) $< -o $@

# Instantiate build directory
build:
	@mkdir build

# Remove objects and binaries
clean:
	@rm -rf build test cli

CC = g++
CPPFLAGS = -Wall -I./src

# Object files for the cli executable
CLI_OBJECTS = build/parser.o build/token.o build/lexer.o build/evaluator.o build/ui.o

# Object files for the test executable
TEST_OBJECTS = build/parser.o build/token.o build/lexer.o build/evaluator.o build/cases.o build/testing.o
# Default target to build both executables
all: cli test
# Target to build the cli executable
cli: $(CLI_OBJECTS)
	$(CC) $(CPPFLAGS) $(CLI_OBJECTS) -o cli
# Target to build the test executable
test: $(TEST_OBJECTS)
	$(CC) $(CPPFLAGS) $(TEST_OBJECTS) -o test
# Pattern rule to compile .cpp files to .o files
build/%.o: src/%.cpp build
	$(CC) -c $(CPPFLAGS) $< -o $@
# Ensure the build directory exists
build:
	mkdir -p build

# Clean build artifacts and executables
clean:
	rm -rf build cli test	

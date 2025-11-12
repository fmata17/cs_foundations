# Makefile

# compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17

# Target executable name
TARGET = main.out

# Source files
SRC = main.cpp

# Default rule
all: $(TARGET)
	@clear
	@echo "Running $(TARGET)..."
	@./$(TARGET)
	@$(MAKE) clean

# Compile only if needed
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean rule
clean:
	rm -f $(TARGET)

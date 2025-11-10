# Makefile for TinyShell

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
TARGET = tinyshell
SOURCE = tinyshell.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

test: $(TARGET)
	@echo "Testing tinyshell..."
	@echo "Type 'exit' to quit the shell"
	./$(TARGET)

help:
	@echo "Available targets:"
	@echo "  all     - Build tinyshell"
	@echo "  clean   - Remove compiled files"
	@echo "  install - Install to /usr/local/bin"
	@echo "  test    - Run tinyshell"
	@echo "  help    - Show this help message"
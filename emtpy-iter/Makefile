ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	EXT = .exe
	TIME = powershell -Command "Measure-Command {./$(TARGET) $(ITERS)}"
else
	EXT = 
	TIME = time ./$(TARGET) $(ITERS)
endif

TARGET = main$(EXT)
CXXFLAGS += -O0

all: build

$(TARGET): main.cpp Makefile
	$(CXX) $(CXXFLAGS) $< -o $(TARGET)

build: $(TARGET)

run: build
	$(TIME)

.PHONY:
	all run

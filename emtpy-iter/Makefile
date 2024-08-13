ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	EXT = .exe
endif

TARGET = main$(EXT)
CXXFLAGS += -O2

all: build

$(TARGET): main.cpp Makefile
	$(CXX) $(CXXFLAGS) $< -o $(TARGET)

build: $(TARGET)

run: build
	$(TARGET)

.PHONY:
	all run
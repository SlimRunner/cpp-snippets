ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	RM = del /Q /S
	FixPath = $(subst /,\,$1)
	MD = if not exist $1 mkdir $1
endif
ifeq ($(detected_OS),Linux)
	RM = rm -rf
 	FixPath = $1
	MD = mkdir -p $1
endif

CXX := g++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := ArgParser
INCLUDE  := -I include/
SRC      :=                      \
	$(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	$(call MD,$(call FixPath,$(@D)))
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	$(call MD,$(call FixPath,$(@D)))
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	$(call MD,$(call FixPath,$(APP_DIR)))
	$(call MD,$(call FixPath,$(OBJ_DIR)))

debug: CXXFLAGS += -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	$(RM) $(call FixPath,$(OBJ_DIR)/*)
	$(RM) $(call FixPath,$(APP_DIR)/*)

info:
	@echo "[*] Application dir: ${APP_DIR}"
	@echo "[*] Object dir:      ${OBJ_DIR}"
	@echo "[*] Sources:         ${SRC}"
	@echo "[*] Objects:         ${OBJECTS}"
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
	@echo "[*] Detected OS:     ${detected_OS}"

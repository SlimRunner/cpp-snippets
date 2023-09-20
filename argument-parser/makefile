#### LINUX COMMS ####
RM = rm -f
FixPath = $1

define MD
	mkdir -p $1
endef
#####################

### WINDOWS COMMS ###
# RM = del /Q /S
# FixPath = $(subst /,\,$1)

# define MD
# 	if not exist $1 mkdir $1
# endef
#####################

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
	echo "[*] Application dir: ${APP_DIR}     "
	echo "[*] Object dir:      ${OBJ_DIR}     "
	echo "[*] Sources:         ${SRC}         "
	echo "[*] Objects:         ${OBJECTS}     "
	echo "[*] Dependencies:    ${DEPENDENCIES}"

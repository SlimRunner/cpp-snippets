OBJDIR := ./objects
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(addprefix objects/,$(patsubst %.cpp,%.o,$(SOURCES)))
DEPENDS := $(patsubst %.o,%.d,$(OBJECTS))
INCLUDE := -I include/
TARGET  := parking.exe

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

CURRENT_TARGET := $(MAKECMDGOALS)

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean info

# The first rule is the default, ie. "make",
# "make all" and "make parking" mean the same
all: info

clean:
	$(RM) $(OBJECTS) $(DEPENDS) $(TARGET)

# Linking the executable from the object files
$(TARGET): $(OBJECTS)
	$(CXX) $(WARNING) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

$(OBJDIR)/%.o: %.cpp Makefile
	$(CXX) $(WARNING) $(INCLUDE) $(CXXFLAGS) -MMD -MP -c $< -o $@

info:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(DEPENDS)
	@echo $(CURRENT_TARGET)

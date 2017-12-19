########################
### IMACMAN Makefile ###
########################

#THE TARGET
TARGETNAME := IMACMAN
TARGET := Game/$(TARGETNAME)

# SETUP
CXX := g++
SRCDIR := .
SRCEXT := cpp
LIBDIR := libs

# FIND ALL PROJECT SOURCES
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
OBJECTS := $(SOURCES:.$(SRCEXT)=.o)

# COMPILER FLAGS
CXXFLAGS := -g -std=c++11 -Wall -pedantic
LDLIBS := $(pkg-config --libs assimp)
LDFLAGS := -I $(LIBDIR)/boost $(pkg-config --cflags assimp) -L$(LIBDIR)

# OS-DEPENDANT COMPILER FLAGS
UNAME_S := $(shell uname -s)
# Windows (cygwin)
ifeq ($(OS),Windows_NT)
LDLIBS += -lGL -lSDL2 -lSDL2_image
LDFLAGS +=

# OS X
else ifeq ($(UNAME_S),Darwin)
LDLIBS += -framework OpenGL -framework SDL2 -framework SDL2_image
LDFLAGS +=
CXXFLAGS +=
CXX := g++

# Linux (default)
else
LDLIBS += -lGL -lSDL2 -lSDL2_image
LDFLAGS +=
CXXFLAGS +=
endif


# BUILD THE PROGRAM
$(TARGET): hello linker

#SAY HELLO
hello:
	@echo "\n========================================"
	@echo "   COMPILING $(TARGETNAME) on $(UNAME_S)"
	@echo "========================================\n"

#LINK EVERYTHING
linker: $(OBJECTS)
	@echo "\n  Compiling ok!"
	@echo "\n========================================"
	@echo "   LINKING"
	@echo "========================================\n"
	@echo "  $(CXX) $^ -o $(TARGET) $(LDFLAGS) $(LDLIBS) $(OSLIB)\n"; $(CXX) $^ -o $(TARGET) $(LDFLAGS) $(LDLIBS) $(OSLIB)
#    @echo "  Cleaning objects..."
#    @$(RM) -r $(OBJECTS)
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET) to launch $(TARGETNAME)\""
	@echo "========================================\n"

# COMPILE THE SOURCES
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "  $(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<"; $(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<
	@mkdir -p $(BUILDDIR)

# REMOVE ALL OBJECTS
clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(OBJECTS) $(TARGET)"; $(RM) -r $(OBJECTS) $(TARGET)

.PHONY: clean

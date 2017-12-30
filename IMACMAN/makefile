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

UNAME_S := $(shell uname -s)

# FIND ALL PROJECT SOURCES
ifeq ($(OS),Windows_NT)
SOURCES := $(shell tree $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
else
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
endif
OBJECTS := $(SOURCES:.$(SRCEXT)=.o)

# COMPILER FLAGS
CXXFLAGS := -g -std=c++11 -Wall -pedantic -I$(LIBDIR)
LDLIBS := `pkg-config --libs assimp` `pkg-config --libs freetype2`
LDFLAGS := `pkg-config --cflags assimp` `pkg-config --cflags freetype2`

# OS-DEPENDANT COMPILER FLAGS
# Windows (cygwin)
ifeq ($(OS),Windows_NT)
LDLIBS += -lGL -lSDL2 -lSDL2_image -lGLEW

# OS X
else ifeq ($(UNAME_S),Darwin)
LDLIBS += -framework OpenGL -framework SDL2 -framework SDL2_image -lGLEW

# Linux (default)
else
LDLIBS += -lGLEW -lGL -lSDL2 -lSDL2_image
endif

CXXFLAGS += $(LDFLAGS)


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

########################
### IMACMAN Makefile ###
########################

#THE TARGET
TARGETNAME := IMACMAN
TARGET := Game/$(TARGETNAME)

# SETUP
CC := g++
SRCDIR := .
BUILDDIR := Game/build
SRCEXT := cpp
LIBDIR := libs

# FIND ALL PROJECT SOURCES
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
OBJECTS := $(SOURCES:.$(SRCEXT)=.o)


# COMPILER FLAGS
CFLAGS := -std=c++11 -Wall
LIB := $(pkg-config --libs assimp)
INC := -I libs/boost $(pkg-config --cflags assimp)


# OS-DEPENDANT COMPILER FLAGS
UNAME_S = $(shell uname -s)
# Windows (cygwin)
ifeq ($(OS),Windows_NT)
	OSLIB := -lGL -lSDL -lSDL_image
	OSINC :=

# OS X
else ifeq ($(UNAME_S),Darwin)
	OSLIB = -framework OpenGL -framework SDL2 -framework SDL2_image
	OSINC :=

# Linux (default)
else
	OSLIB :=
	OSINC := -lGL
endif


# BUILD THE PROGRAM
$(TARGET): clean hello linker

hello:
	@echo "\n========================================"
	@echo "   COMPILING $(TARGETNAME) on $(UNAME_S)"
	@echo "========================================\n"

linker: $(OBJECTS)
	@echo "\n  Compiling ok!"
	@echo "\n========================================"
	@echo "   LINKING"
	@echo "========================================\n"
	@echo "  $(CC) $^ -o $(TARGET) $(LIB) $(OSLIB)\n"; $(CC) $^ -o $(TARGET) $(LIB) $(OSLIB)
	@echo "  Cleaning objects..."
	@$(RM) -r $(OBJECTS)
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET) to launch $(TARGETNAME)\""
	@echo "========================================\n"

# COMPILE THE SOURCES
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "  $(CC) $(CFLAGS) $(INC) $(OSINC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) $(OSINC) -c -o $@ $<

	@mkdir -p $(BUILDDIR)

# REMOVE ALL OBJECTS
clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(OBJECTS) $(TARGET)"; $(RM) -r $(OBJECTS) $(TARGET)

.PHONY: clean

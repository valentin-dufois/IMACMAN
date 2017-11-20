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
OBJECTS := $(patsubst %.cpp,$(BUILDDIR)/%.o,$(SOURCES:.$(SRCEXT)=.o))


# COMPILER FLAGS
CFLAGS := -std=c++11 -Wall
LIB := $(pkg-config --libs assimp) -framework OpenGL
INC := -I libs/boost $(pkg-config --cflags assimp)


# OS-DEPENDANT COMPILER FLAGS
# Windows (cygwin)
ifeq "$(OS)" "Windows_NT"
LIB := $(LIB) -lGL
INC := $(INC)

# OS X
else ifeq "$(OSTYPE)" "darwin"
LIB := $(LIB) -framework OpenGL
INC := $(INC)

# Linux (default)
else
LIB := $(LIB)
INC := $(INC) -lGL
endif



# BUILD THE PROGRAM
$(TARGET): $(OBJECTS)
	@echo "\n  Compiling ok!"
	@echo "\n========================================"
	@echo "   LINKING"
	@echo "========================================\n"
	@echo "  $(CC) $^ -o $(TARGET) $(LIB)\n"; $(CC) $^ -o $(TARGET) $(LIB)
	@echo "  Cleaning objects..."
	@$(RM) -r $(BUILDDIR)
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET) to launch $(TARGETNAME)\""
	@echo "========================================\n"

# COMPILE THE SOURCES
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) startMessage
	@echo "  $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

startMessage:
	@echo "\n========================================"
	@echo "   COMPILING IMACMAN"
	@echo "========================================\n"
	@mkdir -p $(BUILDDIR)

# REMOVE ALL OBJECTS
clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean

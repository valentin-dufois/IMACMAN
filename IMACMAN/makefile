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

# FIND ALL PROJECT SOURCES
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# COMPILER FLAGS
CFLAGS := -g -std=c++11 -Wall
LIB :=
INC :=

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

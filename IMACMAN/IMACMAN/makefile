########################
### IMACMAN Makefile ###
########################

#THE TARGET
TARGET := Game/IMACMAN

# SETUP
CC := g++ # Compiler
SRCDIR := .
BUILDDIR := Game/build
SRCEXT := cpp

# FIND ALL PROJECT SOURCES
SOURCES := $(shell find $(SRCDIR) -type f -name **.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# COMPILER FLAGS
CFLAGS := -g # -Wall
LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include

# BUILD THE PROGRAM
$(TARGET): $(OBJECTS)
@echo " Linking..."
@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

# COMPILE THE SOURCES
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
@mkdir -p $(BUILDDIR)
@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

# REMOVE ALL OBJECTS
clean:
@echo " Cleaning...";
@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean

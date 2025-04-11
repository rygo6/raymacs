# Makefile for compiling a raylib project with GCC on Windows
# Uses W64DevKit and specific raylib path structure

# Project name (used for output file)
NAME = raymacs

# Compiler & linker
CC = gcc
RAYLIB_PATH = C:/raylib/raylib
COMPILER_PATH = C:/raylib/w64devkit/bin

# Fix path separator for Windows
RAYLIB_PATH_FIX = $(subst \,/,$(RAYLIB_PATH))

# Compiler flags
CFLAGS = -s -static -O2 -std=c99 -Wall -I$(RAYLIB_PATH_FIX)/src -Iexternal -DPLATFORM_DESKTOP

# Linker flags
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin
RESDIR = resources

# Source file (as specified)
MAIN_SRC = main.c

# Output file
OUTPUT = $(BINDIR)/$(NAME).exe

# Source files & object files
SOURCES = $(wildcard $(SRCDIR)/$(MAIN_SRC) $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
RESOURCE = $(RAYLIB_PATH_FIX)/src/raylib.rc.data

# Detect OS for mkdir and copy commands
ifeq ($(OS),Windows_NT)
    MKDIR = mkdir -p
    RM = rm -rf
    CP = cp -r
else
    MKDIR = mkdir -p
    RM = rm -rf
    CP = cp -r
endif

# Compilation rules
all: directories $(OUTPUT) copy_resources run

$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ $(RESOURCE) -L$(RAYLIB_PATH_FIX)/src -L$(RAYLIB_PATH_FIX)/src/external/glfw/lib $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

directories:
	$(MKDIR) $(BINDIR)
	$(MKDIR) $(OBJDIR)
	# Ensure resources directory exists
	$(MKDIR) $(RESDIR)

clean:
	$(RM) $(OBJDIR)
	$(RM) $(BINDIR)
	@echo "Cleaned build directories"

run:
	./$(OUTPUT)

# Copy resources to the binary directory
copy_resources:
	@echo "Copying resources to bin/resources directory..."
	$(MKDIR) $(BINDIR)/$(RESDIR)
	$(CP) $(RESDIR)/* $(BINDIR)/$(RESDIR)/ 2>/dev/null || :
	@echo "Resources copied successfully"

.PHONY: all clean run directories copy_resources

# Example Usage:
# 
# mingw32-make                     # Compile with default name (raymacs)
# mingw32-make NAME=mygame         # Compile the project with custom name
# mingw32-make clean               # Remove object files and binary
# mingw32-make run                 # Run the compiled binary
# mingw32-make copy_resources      # Copy resources to bin directory for distribution
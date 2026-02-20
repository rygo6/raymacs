# Detect OS
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := $(shell uname -s)
endif

# Compiler and flags
CC := gcc
CSTD := -std=gnu11
PLATFORM := PLATFORM_DESKTOP_SDL
RAYLIB_LIBTYPE := STATIC
GRAPHICS := GRAPHICS_API_OPENGL_33

# Paths
RAYLIB_PATH := raylib
RAYLIB_SRC := $(RAYLIB_PATH)/src
RAYLIB_URL := https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
RAYLIB_VERSION := 5.5

SRC_DIR := src
BIN_DIR := bin

# Source files
SOURCES := $(SRC_DIR)/main.c

# Base compiler flags
CFLAGS := -g $(CSTD) -march=native -mtune=native
CFLAGS += -I$(RAYLIB_SRC)

# Warning flags
CFLAGS += -Wall -Wextra -Werror -Wshadow -Wformat=2
CFLAGS += -Wno-unused-variable -Wno-unused-function -Wno-unused-label -Wno-unused-but-set-variable -Wno-unused-parameter

# Base linker flags
LDFLAGS := -L$(RAYLIB_SRC) -L.

# OS-specific settings
ifeq ($(DETECTED_OS),Windows)
    OUTPUT := $(BIN_DIR)/rayDE.exe
    RAYLIB_LIB := $(RAYLIB_SRC)/libraylib.a
    LDFLAGS += -static-libgcc -Wl,--allow-multiple-definition
    LIBS := -lraylib -lopengl32 -lgdi32 -lwinmm
    # SDL3 static linking (uncomment to use)
    # LDFLAGS += -L/ucrt64/lib
    # LIBS := -Wl,-Bstatic -lSDL3 -Wl,-Bdynamic -lopengl32 -lgdi32 -lwinmm -lole32 -loleaut32 -luuid -lsetupapi -lversion -limm32
    RAYLIB_MAKE := mingw32-make -C $(RAYLIB_SRC)
else ifeq ($(DETECTED_OS),Darwin)
    # macOS
    OUTPUT := $(BIN_DIR)/rayDE
    RAYLIB_LIB := $(RAYLIB_SRC)/libraylib.a
    LDFLAGS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreAudio
    LIBS := -lraylib -lm
    # SDL3 static linking (uncomment to use)
    # LIBS := -lSDL3 -lraylib -lm
    RAYLIB_MAKE := make -C $(RAYLIB_SRC)
else
    # Linux
    OUTPUT := $(BIN_DIR)/rayDE
    RAYLIB_LIB := $(RAYLIB_SRC)/libraylib.a

    # Auto-detect display server
    HAS_WAYLAND := $(shell pkg-config --exists wayland-client 2>/dev/null && echo TRUE || echo FALSE)
    HAS_X11     := $(shell pkg-config --exists x11 2>/dev/null && echo TRUE || echo FALSE)

    ifeq ($(HAS_WAYLAND),TRUE)
        ifeq ($(HAS_X11),TRUE)
            # Both installed: prefer current session
            ifneq ($(WAYLAND_DISPLAY),)
                DISPLAY_SERVER := Wayland
            else
                DISPLAY_SERVER := X11
            endif
        else
            DISPLAY_SERVER := Wayland
        endif
    else
        DISPLAY_SERVER := X11
    endif

    # Common Linux linker flags
    LDFLAGS += -lGL -lpthread -ldl -lrt
    LIBS := -lraylib -lm

    ifeq ($(DISPLAY_SERVER),Wayland)
        LDFLAGS += -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon
        RAYLIB_MAKE := make -C $(RAYLIB_SRC) RAYLIB_LIBTYPE=$(RAYLIB_LIBTYPE) GRAPHICS=$(GRAPHICS) GLFW_LINUX_ENABLE_WAYLAND=TRUE GLFW_LINUX_ENABLE_X11=FALSE
    else
        RAYLIB_MAKE := make -C $(RAYLIB_SRC) RAYLIB_LIBTYPE=$(RAYLIB_LIBTYPE) GRAPHICS=$(GRAPHICS)
    endif
endif

# Default target - build only
.PHONY: all
all: raylib $(OUTPUT)

# Download and build raylib
.PHONY: raylib
raylib: $(RAYLIB_LIB)

$(RAYLIB_LIB):
	@echo Downloading raylib $(RAYLIB_VERSION)...
	@curl -L -o raylib.tar.gz $(RAYLIB_URL)
	@echo Extracting raylib...
	@tar -xzf raylib.tar.gz
	@mv raylib-$(RAYLIB_VERSION) $(RAYLIB_PATH)
	@rm raylib.tar.gz
	@echo Building raylib...
	@$(RAYLIB_MAKE)
	@echo Raylib built successfully!

# Build target
$(OUTPUT): $(SOURCES) $(RAYLIB_LIB) | $(BIN_DIR)
	@echo Building for $(DETECTED_OS)...
	$(CC) -o $(OUTPUT) $(SOURCES) $(CFLAGS) $(LDFLAGS) $(LIBS)
	@echo Success!

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Run the executable
.PHONY: run
run: $(OUTPUT)
	@echo Running $(OUTPUT)...
	@./$(OUTPUT)

# Clean build artifacts
.PHONY: clean
clean:
	@echo Cleaning...
	@rm -f $(OUTPUT)

# Clean raylib build
.PHONY: clean-raylib
clean-raylib:
	@echo Cleaning raylib...
	@rm -rf $(RAYLIB_PATH)

# Deep clean (remove bin directory and raylib)
.PHONY: distclean
distclean: clean clean-raylib
	@echo Deep cleaning...
	@rm -rf $(BIN_DIR)

# Build only (explicit)
.PHONY: build
build: all

# Force rebuild of raylib
.PHONY: rebuild-raylib
rebuild-raylib: clean-raylib raylib

# Generate compile_commands.json for clangd
.PHONY: compile_commands
compile_commands:
	@echo Generating compile_commands.json...
	@echo '[' > compile_commands.json
	@echo '  {' >> compile_commands.json
	@echo '    "directory": "$(shell pwd)",' >> compile_commands.json
	@echo '    "command": "$(CC) $(CFLAGS) -c $(SOURCES)",' >> compile_commands.json
	@echo '    "file": "$(SOURCES)"' >> compile_commands.json
	@echo '  }' >> compile_commands.json
	@echo ']' >> compile_commands.json
	@echo compile_commands.json generated!

# Display detected OS
.PHONY: info
info:
	@echo Detected OS: $(DETECTED_OS)
	@echo Display server: $(DISPLAY_SERVER)
	@echo Compiler: $(CC)
	@echo C Standard: $(CSTD)
	@echo Output: $(OUTPUT)
	@echo Raylib path: $(RAYLIB_PATH)
	@echo Raylib library: $(RAYLIB_LIB)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo LIBS: $(LIBS)

# Help target
.PHONY: help
help:
	@echo Available targets:
	@echo   all             - Download/build raylib and build project (default)
	@echo   build           - Same as 'all'
	@echo   raylib          - Download and build raylib only
	@echo   run             - Build and run the executable
	@echo   clean           - Remove built executable
	@echo   clean-raylib    - Remove raylib directory
	@echo   distclean       - Remove bin directory and raylib
	@echo   rebuild-raylib  - Force rebuild of raylib
	@echo   compile_commands - Generate compile_commands.json for clangd
	@echo   info            - Show build configuration
	@echo   help            - Show this help
	@echo.
	@echo Detected OS: $(DETECTED_OS)
	@echo Raylib version: $(RAYLIB_VERSION)
	@echo C Standard: $(CSTD)
	@echo.
	@echo To enable SDL3 static linking, uncomment the appropriate SDL3 LIBS line
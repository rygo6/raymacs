:: How to statically link SDL3 to raylib on UCRT64
:: mingw32-make.exe PLATFORM=PLATFORM_DESKTOP_SDL RAYLIB_LIBTYPE=SHARED GRAPHICS=GRAPHICS_API_OPENGL_33 LDFLAGS="-L. -L../src -L/ucrt64/lib -static-libgcc -Wl,--allow-multiple-definition -Wl,-Bstatic -lSDL3 -Wl,-Bdynamic -lopengl32 -lgdi32 -lwinmm -lole32 -loleaut32 -luuid -lsetupapi -lversion -limm32"

@echo off

SET RAYLIB_PATH=../raylib/

if exist bin\rayDE.exe del bin\rayDE.exe

gcc -o bin/rayDE.exe src/main.c -I"%RAYLIB_PATH%/src" -L"%RAYLIB_PATH%/src" -march=native -mtune=native -lraylib -lopengl32 -lgdi32 -lwinmm -std=c11 -Wall -Wextra -Werror -Wshadow -Wformat=2 -Wno-unused-variable -Wno-unused-function -Wno-unused-label -Wno-unused-but-set-variable

bin\rayDE.exe
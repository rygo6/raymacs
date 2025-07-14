${1} -o bin/raymacs.exe src/main.c -I"${2}/src" -L"${2}/src" -lraylib -lopengl32 -lgdi32 -lwinmm -O0
./bin/raymacs.exe
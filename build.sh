mkdir -p bin
rm ./bin/raymacs
LIBS=$(pkg-config --cflags --libs raylib)
gcc -o bin/raymacs src/main.c $LIBS -lraylib 
./bin/raymacs
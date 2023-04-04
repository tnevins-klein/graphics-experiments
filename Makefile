CC = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -Wstrict-aliasing 
CFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Ilib/SDL/include
LDFLAGS = lib/SDL/build/libSDL3.1.0.0.dylib -Wl,-rpath,lib/SDL/build,-rpath,.

SRC = $(wildcard src/*.c) $(wildcard src/**.c)
OBJ = $(SRC:.c=.o)
BIN = bin

all: libs game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

libs:
	mkdir lib/SDL/build
	cd lib/SDL/build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release --parallel

clean_libs:
	/bin/rm -rf lib/SDL/build

clean:
	/bin/rm -rf $(BIN) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

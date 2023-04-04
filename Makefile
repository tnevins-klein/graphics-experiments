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

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

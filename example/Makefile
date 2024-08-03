ARCH=WASM
CFLAGS-ALL=-std=c89 -Wall -I./external/glfw/include/ -D$(ARCH)

OBJ-LINUX= \
	./01-triangle/main \
	./02-texture/main

OBJ-WASM= \
	./01-triangle/main.wasm \
	./02-texture/main.wasm 

LIB-LINUX=./libglfw.so
CFLAGS-LINUX=-DGLFW
LDFLAGS-LINUX=-lGL -L. -lglfw

CFLAGS-WASM=--target=wasm32 -I/usr/include -I../ 

BIN=$(BIN-$(ARCH))
OBJ=$(OBJ-$(ARCH))
LIB=$(LIB-$(ARCH))
CFLAGS=$(CFLAGS-ALL) $(CFLAGS-$(ARCH))
LDFLAGS=$(LDFLAGS-$(ARCH))

all: $(OBJ)

$(BIN): $(OBJ) $(LIB)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ)
	chmod 644 $(BIN)

./libglfw.so:
	$(CC) -fPIC -shared -D_GLFW_X11 -D_GLFW_BUILD_DLL ./external/glfw/src/*.c -o $@

clean:
	rm $(BIN) $(OBJ) $(LIB)

.SUFFIXES: .c .wasm

.c.wasm:
	$(CC) $(CFLAGS) $(LDFLAGS) --target=wasm32 -nostdlib -Wl,--import-memory,--no-entry,--export-all,--allow-undefined,--export-table -o $@ $< 
	chmod 644 $@

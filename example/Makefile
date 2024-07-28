ARCH=WASM
CFLAGS-ALL=-std=c89 -Wall -I./external/glfw/include/ -D$(ARCH)

LIB-LINUX=./libglfw.so
BIN-LINUX=./main
OBJ-LINUX= ./main.o 
CFLAGS-LINUX=-DGLFW
LDFLAGS-LINUX=-lGL -L. -lglfw

LIB-WASM=
BIN-WASM=main.wasm
OBJ-WASM= ./main.o 

CFLAGS-WASM=--target=wasm32 -I/usr/include -I../ 
LDFLAGS-WASM=--target=wasm32 -nostdlib -Wl,--import-memory,--no-entry,--export-all,--allow-undefined,--export-table

BIN=$(BIN-$(ARCH))
OBJ=$(OBJ-$(ARCH))
LIB=$(LIB-$(ARCH))
CFLAGS=$(CFLAGS-ALL) $(CFLAGS-$(ARCH))
LDFLAGS=$(LDFLAGS-$(ARCH))

$(BIN): $(OBJ) $(LIB)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ)
	chmod 644 $(BIN)

./libglfw.so:
	$(CC) -fPIC -shared -D_GLFW_X11 -D_GLFW_BUILD_DLL ./external/glfw/src/*.c -o $@

clean:
	rm $(BIN) $(OBJ) $(LIB)

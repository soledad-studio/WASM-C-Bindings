CFLAGS-ALL=-std=c89 -Wall -D$(ARCH) -I../external/glfw/include/

BIN-LINUX=main
OBJ-LINUX= main.o 
CFLAGS-LINUX=
LDFLAGS-LINUX=-lGL -lglfw

BIN-WASM=main.wasm
OBJ-WASM= \
	../webgl.o  \
	../util.o  \
	main.o 

CFLAGS-WASM=--target=wasm32  -I/usr/include
LDFLAGS-WASM=--target=wasm32 -nostdlib -Wl,--no-entry,--export-all,--allow-undefined

BIN=$(BIN-$(ARCH))
OBJ=$(OBJ-$(ARCH))
CFLAGS=$(CFLAGS-ALL) $(CFLAGS-$(ARCH))
LDFLAGS=$(LDFLAGS-$(ARCH))

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ)
	chmod 644 $(BIN)

clean:
	rm $(BIN) $(OBJ)

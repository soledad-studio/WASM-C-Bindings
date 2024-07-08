BIN-LINUX=main
OBJ-LINUX= main.o 
CFLAGS-LINUX=-std=c89 -Wall -D$(ARCH)
LDFLAGS-LINUX=-lGL -lglfw

BIN-WASM=main.wasm
OBJ-WASM= \
	main.o \
	../wasm.o 
CFLAGS-WASM=$(CFLAGS-LINUX) --target=wasm32 -I /usr/include 
LDFLAGS-WASM=--target=wasm32 -nostdlib -Wl,--no-entry,--export-all,--allow-undefined

BIN=$(BIN-$(ARCH))
OBJ=$(OBJ-$(ARCH))
CFLAGS=$(CFLAGS-$(ARCH))
LDFLAGS=$(LDFLAGS-$(ARCH))

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJ)
	chmod 644 $(BIN)

clean:
	rm $(BIN) $(OBJ)

JS_OBJS = \
	./wasm/main.js \
	./wasm/glfn.js \
	./wasm/util.js \
	./wasm/webgl.js

WASM_OBJS = \
	./wasm/util.o \
	./wasm/webgl.o 

CFLAGS=--target=wasm32 -fPIC 

wasm: ./glfn.js ./glfn.wasm

./glfn.js: $(JS_OBJS)
	cat $(JS_OBJS) > $@

./glfn.wasm: $(WASM_OBJS)
	wasm-ld --import-memory --no-entry --export-all --allow-undefined  -o $@ $(WASM_OBJS)
	chmod 644 $@

clean:
	rm ./glfn.js ./glfn.wasm $(WASM_OBJS)

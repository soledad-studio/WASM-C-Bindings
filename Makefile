JS_OBJS = \
	./wasm/main.js \
	./wasm/glfn.js \
	./wasm/util.js \
	./wasm/webgl.js

WASM_OBJS = \
	./wasm/libc.o \
	./wasm/webgl.o 

CFLAGS=--target=wasm32 -fPIC -std=c99 

wasm: ./glfn.js ./glfn.wasm

./glfn.js: $(JS_OBJS)
	cat $(JS_OBJS) > $@

./glfn.wasm: $(WASM_OBJS)
	wasm-ld --merge-data-segments --import-memory --no-entry --export-all --allow-undefined -o $@ $(WASM_OBJS)
	chmod 644 $@

clean:
	rm ./glfn.js ./glfn.wasm $(WASM_OBJS)

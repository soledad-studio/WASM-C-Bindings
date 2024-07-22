var gl = null;
var exports = null;

async function load_wasm( src )
{
	let imports = 
	{
		env:
		{
			...imports_util,
			...imports_webgl,
			...imports_glfw,
		}
	}

	exports = (await WebAssembly.instantiateStreaming(fetch(src), imports )).instance.exports;
	exports.main();
}

load_wasm( "./main.wasm" );


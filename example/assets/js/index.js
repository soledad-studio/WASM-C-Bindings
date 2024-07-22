var gl = null;
var exports = null;

async function load_wasm( src )
{
	let imports = 
	{
		env:
		{
			...imports_webgl,
			...imports_util,
		}
	}

	exports = (await WebAssembly.instantiateStreaming(fetch(src), imports )).instance.exports;

	gl = document.getElementById("webgl-canvas").getContext("webgl2");

	exports.main();
}

load_wasm( "./main.wasm" );


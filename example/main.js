
async function load_modules()
{
	await load_wasm( "../glfn.wasm" );
	await load_wasm( "./main.wasm" );
	imports.main();
}

load_modules();

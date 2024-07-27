var ids=[];
var gl = null;
var imports = null;

{
	const memory =  new WebAssembly.Memory(
	{
		initial: 2,
		maximum: 10,
		shared: false,
	});

	imports = 
	{
		'memory': memory,
	}
}


async function load_wasm( src )
{

	let imports_wasm = (await WebAssembly.instantiateStreaming(fetch(src), {env:imports,} )).instance.exports;

	imports = 
	{
		...imports,
		...imports_wasm,
	}

}

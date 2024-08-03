const imports_util = 
{
	_get_str: (c0) =>
	{
		const data = new Uint8Array(imports.memory.buffer, c0, imports.strlen(c0) );
		return new TextDecoder().decode(data);
	},

	_read_file: (c0) =>
	{
		const request = new XMLHttpRequest();
		request.open( "GET", imports._get_str(c0), false );
		request.send( null );
		ids.push( request.responseText );
		return ids.length-1;
	},
	_read_img: (c0) =>
	{
	// Needs Preload
		img = new Image()
		img.src= imports._get_str(c0);
		ids.push( img );
		return ids.length-1;
	},

	console_log: (c0) =>
	{
		console.log( imports._get_str(c0) );
	},
	console_num: (c0) =>
	{
		console.log( c0 );
	},
	console_warn: (c0) =>
	{
		console.warn( imports._get_str(c0) );
	},
	console_error: (c0) =>
	{
		console.error( imports._get_str(c0) );
	},
};

imports=
{
	...imports,
	...imports_util,
}

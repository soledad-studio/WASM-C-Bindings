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
};

imports=
{
	...imports,
	...imports_util,
}

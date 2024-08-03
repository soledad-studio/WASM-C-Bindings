const imports_glfn = 
{
	glfnCreateWindow: (c0, c1, c2 ) =>
	{
		canvas=document.createElement("canvas");
		document.body.appendChild(canvas);

		canvas.width=c0;
		canvas.height=c1;
		canvas.id=imports._get_str(c2);

		ids.push( canvas );
		return ids.length-1;
	},
	glfnMakeContextCurrent: (c0) =>
	{
		gl = ids[c0].getContext( "webgl2", {antialias:false} );
	},
	glfnSetWindowDrawCallback: (c0,c1,c3) =>
	{
		imports.glfnMakeContextCurrent(c0);
		window.setInterval( imports.__indirect_function_table.get(c1), 1000.0/c3 );
	},
	glfnSetScreenSizeCallback: (c0, c1) =>
	{
		window.addEventListener( "resize", function(event) {
			imports.__indirect_function_table.get(c1)( c0, window.innerWidth, window.innerHeight );
		},true);
		imports.__indirect_function_table.get(c1)( c0, window.innerWidth, window.innerHeight );
	},
	glfnSetWindowSize: (c0, c1, c2) =>
	{
		ids[c0].width=c1;
		ids[c0].height=c2;
	},
};

imports =
{
	...imports,
	...imports_glfn,
}

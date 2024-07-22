var ids_glfw = [];

const imports_glfw = 
{
	glfwInit: () =>
	{
	},
	glfwCreateWindow: (c0, c1, c2, c3, c4, c5 ) =>
	{
		canvas=document.createElement("canvas");
		document.body.appendChild(canvas);

		canvas.width=c0;
		canvas.height=c1;
		canvas.id=imports_util._get_str(c2);


		ids_glfw.push( canvas );
		return ids_glfw.length-1;
	},
	glfwMakeContextCurrent: (c0) =>
	{
		gl = ids_glfw[c0].getContext( "webgl2" );
	},
};

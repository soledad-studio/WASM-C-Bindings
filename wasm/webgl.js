const imports_webgl =
{
	glGetError: () =>
	{
		return gl.getError();
	},
	glEnable: (c0) =>
	{
		return gl.enable(c0);
	},
	glPixelStorei: (c0, c1 ) =>
	{
		return gl.pixelStorei(c0,c1);
	},
	glCullFace: (c0) =>
	{
		return gl.cullFace(c0);
	},
	glFrontFace: (c0) =>
	{
		return gl.frontFace(c0);
	},
	glDepthFunc: (c0) =>
	{
		return gl.depthFunc(c0);
	},
	glBlendFunc: (c0,c1) =>
	{
		return gl.blendFunc(c0,c1);
	},

	glViewport: (c0,c1,c2,c3) =>
	{
		return gl.viewport(c0,c1,c2,c3);
	},

	glClearColor: (c0,c1,c2,c3) => 
	{ 
		return gl.clearColor(c0,c1,c2,c3); 
	},
	glClear: (c0) => 
	{ 
		return gl.clear(c0); 
	},

	glDrawArrays: (c0,c1,c2) => 
	{ 
		return gl.drawArrays(c0,c1,c2); 
	},

	glCreateVertexArray: () =>
	{
		ids.push(gl.createVertexArray());
		return ids.length-1;
	},
	glBindVertexArray: (c0) =>
	{
		return gl.bindVertexArray(ids[c0]);
	},
	glDeleteVertexArray: (c0) =>
	{
		return gl.deleteVertexArray(ids[c0]);
	},
	glEnableVertexAttribArray: (c0) =>
	{
		return gl.enableVertexAttribArray(c0);
	},
	glVertexAttribPointer: (c0,c1,c2,c3,c4,c5) =>
	{
		let xd= gl.vertexAttribPointer(c0,c1,c2,c3,c4,c5);
		console.log( gl.getError() );
		return xd;
	},

	glCreateBuffer: () =>
	{
		ids.push(gl.createBuffer());
		return ids.length-1;
	},
	glDeleteBuffer: (c0) =>
	{
		return gl.deleteBuffer(ids[c0]);
	},
	glBindBuffer: (c0,c1) =>
	{
		return gl.bindBuffer(c0,ids[c1]);
	},
	glBufferData: (c0,c1,c2,c3) =>
	{
		const data = new Uint8Array(imports.memory.buffer);
		return gl.bufferData(c0,data,c3,c2,c1);
	},

	glCreateProgram: () =>
	{
		ids.push(gl.createProgram());
		return ids.length-1;
	},
	glUseProgram: (c0) =>
	{
		return gl.useProgram( ids[c0] );
	},
	glLinkProgram: (c0) =>
	{
		return gl.linkProgram( ids[c0] );
	},
	glDeleteProgram: (c0) =>
	{
		return gl.deleteProgram( ids[c0] );
	},

	glGetShaderInfoLog: (c0) =>
	{
		ids.push( gl.getShaderInfoLog( ids[c0] ) );
		console.log( ids[ids.length-1] );
		return ids.length-1;
	},
	glCreateShader: (c0) =>
	{
		ids.push(gl.createShader(c0));
		return ids.length-1;
	},
	_glShaderSource: (c0,c1) =>
	{
		gl.shaderSource( ids[c0], ids[c1] );
	},
	glCompileShader: (c0) =>
	{
		return gl.compileShader( ids[c0] );
	},
	glGetShaderParameter: (c0, c1) =>
	{
		return gl.getShaderParameter( ids[c0], c1 );
	},
	glAttachShader: (c0,c1) =>
	{
		return gl.attachShader( ids[c0], ids[c1]);
	},
	glDeleteShader: (c0) =>
	{
		return gl.deleteShader( ids[c0] );
	},

	glGetUniformLocation: (c0, c1) => 
	{
		ids.push( gl.getUniformLocation( ids[c0], imports._get_str(c1)  ) );
		return ids.length-1;
	},
	glUniform1f: (c0,c1) =>
	{
		return gl.uniform1f( ids[c0] , c1 )
	},
	glUniformMatrix4fv: (c0,c1,c2,c3) =>
	{
		const data = new Uint8Array(imports.memory.buffer);
		return gl.uniformMatrix4fv( ids[c0], c2,data, c3, c1*16 )
	},
	glBindTexture: (c0,c1) =>
	{
		return gl.bindTexture( c0, ids[c1] );
	},
	glCreateTexture: () =>
	{
		ids.push( gl.createTexture() );
		return ids.length-1;
	},
	glDeleteTexture: (c0) =>
	{
		return gl.deleteTexture( ids[c0] );
	},
	glTexParameteri: (c0,c1,c2) =>
	{
		return gl.texParameteri( c0, c1, c2 );
	},
	glTexImage2D: (c0,c1,c2,c3,c4,c5,c6,c7,c8 ) =>
	{
		return gl.texImage2D( c0,c1,c2,c3,c4,c5,c6,c7,ids[c8] );
	},
	glTexImage3D: (c0,c1,c2,c3,c4,c5,c6,c7,c8,c9 ) =>
	{
		if( c9 )
			return gl.texImage3D( c0,c1,c2,c3,c4,c5,c6,c7,c8,ids[c9] );
		return gl.texImage3D( c0,c1,c2,c3,c4,c5,c6,c7,c8,null );
	},
	glTexSubImage3D: (c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10 ) =>
	{
		const data = new Uint8Array(imports.memory.buffer);
		return gl.texSubImage3D( c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,data, c10 );
	},

	glCreateFramebuffer: () =>
	{
		ids.push( gl.createFramebuffer() );
		return ids.length-1;
	},
	glBindFramebuffer: (c0, c1) =>
	{
		if( c1 )
			return gl.bindFramebuffer(c0, ids[c1]);
		return gl.bindFramebuffer(c0, null);

	},
	glBlitFramebuffer: (c0,c1,c2,c3,c4,c5,c6,c7,c8,c9) =>
	{
		return gl.blitFramebuffer(c0,c1,c2,c3,c4,c5,c6,c7,c8,c9);
	},
	glFramebufferTexture2D: (c0,c1,c2,c3,c4) =>
	{
		return gl.framebufferTexture2D( c0, c1, c2, ids[c3], c4 );
	},
	glFramebufferRenderbuffer: (c0,c1,c2,c3) =>
	{
		return gl.framebufferRenderbuffer(c0,c1,c2,ids[c3]);
	},

	glCreateRenderbuffer: () =>
	{
		ids.push( gl.createRenderbuffer() );
		return ids.length-1;
	},
	glBindRenderbuffer: (c0, c1) =>
	{
		return gl.bindRenderbuffer(c0, ids[c1]);
	},
	glRenderbufferStorage: (c0,c1,c2,c3 ) =>
	{
		return gl.renderbufferStorage(c0,c1,c2,c3 ); 
	},
};

imports=
{
	...imports,
	...imports_webgl
}

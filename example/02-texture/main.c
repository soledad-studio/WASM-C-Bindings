#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

char * _read_file( char * );

#ifndef WASM
#include <stb_image.h>
#include <GLFW/glfw3.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
char * _read_file( char * src )
{
	int fd, len;
	fd=open( src, O_RDONLY );
	if( fd == -1 )
		return 0;
	len=lseek( fd, 0, SEEK_END );
	return mmap( 0, len, PROT_READ, MAP_PRIVATE, fd, 0 );
}
#else
#include <glfn.h>
#endif

int positions[] = 
{
	-1,-1,0,
	1,-1,0,
	0,1,0,
};


void draw( void )
{
	glClearColor( (float)0xf6/0xff, (float)0xf4/0xff, (float)0xf1/0xff, (float)0xff/0xff );
	glDrawArrays( GL_TRIANGLES, 0, 3 );
}

int main( void )
{
	void * window;
	unsigned int shaderProgram, vertexArray, texture;

#ifndef WASM
	glfwInit();
	window=glfwCreateWindow( 256, 192, "xd", NULL, NULL );
	glfwMakeContextCurrent(window);
#else
	window=glfnCreateWindow( 256, 192, "xd" );
	glfnMakeContextCurrent(window);
#endif

	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	shaderProgram=glCreateProgram();
	{
		int status, vertexShader;
		char * vsSource;

		vsSource=_read_file( "./vertex.glsl" );

		vertexShader=glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, (void*)&vsSource, NULL );
		glCompileShader( vertexShader );
		glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &status );
		if( !status )
			return 1;
		glAttachShader( shaderProgram, vertexShader );
		glDeleteShader( vertexShader );
	}

	{
		int status, fragmentShader;
		char * fsSource;

		fsSource=_read_file( "./fragment.glsl" );

		fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, (void*)&fsSource, NULL );
		glCompileShader( fragmentShader );
		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &status );

		if( !status )
			return 1;

		glAttachShader( shaderProgram, fragmentShader );
		glDeleteShader( fragmentShader );
	}

	glLinkProgram( shaderProgram );
	glUseProgram( shaderProgram );

	glGenVertexArrays( 1, &vertexArray );
	glBindVertexArray( vertexArray );

	glUseProgram( shaderProgram );

	glGenVertexArrays( 1, &vertexArray );
	glBindVertexArray( vertexArray );

	{
		unsigned int positionBuffer;
		glGenBuffers( 1, &positionBuffer );
		glBindBuffer( GL_ARRAY_BUFFER, positionBuffer );
		glBufferData( GL_ARRAY_BUFFER, 9*sizeof(int), (void*)positions, GL_STATIC_DRAW );
		glVertexAttribPointer( 0, 3, GL_INT, GL_FALSE, 0, 0 );
		glEnableVertexAttribArray(0);
	}

	{
		void * data;
#ifndef WASM
		int w,h,c;
		data=stbi_load( "./simple.png", &w, &h, &c, 0 );
#else
		glPixelStorei( GL_UNPACK_FLIP_Y_WEBGL, GL_TRUE );
		data=(void *)_read_img( "./simple.png" );
#endif
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
	}


#ifndef WASM
	while( !glfwWindowShouldClose(window) )
	{
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
#else
	glfnSetWindowDrawCallback( window, draw, 60 );
#endif
}

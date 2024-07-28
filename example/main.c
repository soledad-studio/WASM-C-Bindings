#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

char * _read_file( char * );

#ifndef WASM
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

float colors[]  =
{
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
};

float positions[] = 
{
	-0.5,-0.5,0.0,
	0.5,-0.5,0.0,
	0.0,0.5,0.0,
};

void draw( void )
{
	glClearColor( 0, 0, 0, 1 );
	glClear( GL_COLOR_BUFFER_BIT );
	glDrawArrays( GL_TRIANGLES, 0, 3 );
}

int main( void )
{
	void * window;
	unsigned int shaderProgram, vertexArray;

#if GLFW
	glfwInit();
	window=glfwCreateWindow( 256, 192, "xd", NULL, NULL );
	glfwMakeContextCurrent(window);
#else
	window=glfnCreateWindow( 256, 192, "xd" );
	glfnMakeContextCurrent(window);
#endif

	shaderProgram=glCreateProgram();

	{
		int status, vertexShader;
		char * vsSource;

		vsSource=_read_file( "./shaders/vertex.glsl" );

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

		fsSource=_read_file( "./shaders/fragment.glsl" );

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

	{
		unsigned int positionBuffer;
		glGenBuffers( 1, &positionBuffer );
		glBindBuffer( GL_ARRAY_BUFFER, positionBuffer );
		glBufferData( GL_ARRAY_BUFFER, 9*sizeof(float), (void*)positions, GL_STATIC_DRAW );
		glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
		glEnableVertexAttribArray(0);
	}

	{
		unsigned int colorBuffer;
		glGenBuffers( 1, &colorBuffer );
		glBindBuffer( GL_ARRAY_BUFFER, colorBuffer );
		glBufferData( GL_ARRAY_BUFFER, 9*sizeof(float), (void*)colors, GL_STATIC_DRAW );
		glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0 );
		glEnableVertexAttribArray(1);	
	}


	
#if GLFW
	while( !glfwWindowShouldClose(window) )
	{
		draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
#else
	glfnSetDrawCallback( window, draw );
#endif
}

int glCreateBuffer( void );
int glCreateVertexArray( void );
int glCreateTexture( void );
int glCreateFramebuffer( void );
int glCreateRenderbuffer( void );
void glDeleteVertexArray( unsigned int );
void glDeleteBuffer( unsigned int );
void glDeleteTexture( unsigned int );
void _glShaderSource( unsigned int shader, const char * sources );
unsigned int glGetShaderParameter( unsigned int shader, unsigned int pname );

void glGenBuffers(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		*(ids+i) = glCreateBuffer();
}

void glGenVertexArrays(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		*(ids+i) = glCreateVertexArray();
}

void glGenTextures(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		*(ids+i) = glCreateTexture();
}

void glGenFramebuffers(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		*(ids+i) = glCreateFramebuffer();
}

void glGenRenderbuffers(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		*(ids+i) = glCreateRenderbuffer();
}

void glDeleteVertexArrays(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		glDeleteVertexArray(*(ids+i));
}

void glDeleteBuffers(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		glDeleteBuffer(*(ids+i));
}

void glDeleteTextures(int n, unsigned int * ids)
{
	int i;
	for( i=0; i<n; ++i )
		glDeleteTexture(*(ids+i));
}

void glGetShaderiv( unsigned int shader, unsigned int pname, int * status )
{
	*status=glGetShaderParameter( shader, pname );
}

void glShaderSource( unsigned int shader, int n, const char * const * sources, const int * lengths )
{
	int i;
	for( i=0; i<n; ++i )
		_glShaderSource( shader, sources[i] );
}

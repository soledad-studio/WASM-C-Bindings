int glCreateBuffer( void );
int glCreateVertexArray( void );

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

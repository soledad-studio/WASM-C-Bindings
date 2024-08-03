void * memset( void * p, int value, unsigned long length )
{
	return __builtin_memset( p, value, length );
}

void * memcpy( void * dest, const void * src, unsigned long length )
{
	return __builtin_memcpy( dest, src, length );
}

unsigned long strlen( const char * str )
{
	char * p = (char*)str;	
	while( *p )
		++p;
	return p-str;
}

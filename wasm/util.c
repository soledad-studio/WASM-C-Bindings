unsigned long strlen( const char * str )
{
	char * p = (char*)str;	
	while( *p )
		++p;
	return p-str;
}

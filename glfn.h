#define NULL ((void*)0)
typedef void (*GLFNFunWindowDraw)(void );
typedef void (*GLFNFunScreenSize)(void *, int, int );
void * glfnCreateWindow( int,  int, char * );
void glfnMakeContextCurrent(void *); 
void glfnSetWindowSize( void *, int, int );
void glfnSetWindowDrawCallback( void *, GLFNFunWindowDraw, int );
void glfnSetScreenSizeCallback( void *, GLFNFunScreenSize );

char * _read_file( char * );
void * _read_img( char * );

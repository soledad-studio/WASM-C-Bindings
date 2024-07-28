#define NULL ((void*)0)
typedef void (*GLFNFunDrawCallback)(void );
void * glfnCreateWindow( int,  int, char * );
void glfnMakeContextCurrent(void *); 
void glfnSetDrawCallback(void *, GLFNFunDrawCallback); 

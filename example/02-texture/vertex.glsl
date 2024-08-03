#version 300 es
layout (location=0) in vec4 position;

out vec2 texCoords;

void main()
{
	texCoords=vec2( position );
	gl_Position=position;
}


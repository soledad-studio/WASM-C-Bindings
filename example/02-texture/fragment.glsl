#version 300 es
precision highp float;

uniform sampler2D Texture;
in vec2 texCoords;
out vec4 fragColor;

void main()
{
	fragColor = vec4( texture( Texture, texCoords ) );
}

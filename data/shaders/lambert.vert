/*-----------------------------------------------------------------------------
*  	CREATED:
*   	20 V 2017
*  	CONTRIBUTORS:
*      	Piotr Makal
*  	INFO:
*      	Lambert vertex shader.
*-----------------------------------------------------------------------------*/

#version 330

/*-----------------------------------------------------------------------------
*	IN/OUT
*-----------------------------------------------------------------------------*/
layout(location = 0) in vec3 g_position;
layout(location = 1) in vec3 g_normal;
layout(location = 2) in vec2 g_texCoord;

//INTERFACE BLOCKS
out VertexData {
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} VertexOut;

/*-----------------------------------------------------------------------------
*	UNIFORMS
*-----------------------------------------------------------------------------*/
uniform mat4 g_transformMatrix;
uniform mat4 g_modelMatrix;

/*-----------------------------------------------------------------------------
*   FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
void main()
{
	VertexOut.position = 	(g_modelMatrix * vec4(g_position, 1.0f)).xyz;
	VertexOut.normal = 		normalize((transpose(inverse(g_modelMatrix)) * vec4(g_normal, 0.0f)).xyz);
	VertexOut.texCoord = 	vec2(g_texCoord.x, 1.0f - g_texCoord.y);

	gl_Position = 			g_transformMatrix * vec4(g_position, 1.0f);
}
/*-----------------------------------------------------------------------------
*  	CREATED:
*   	20 V 2017
*  	CONTRIBUTORS:
*      	Piotr Makal
*  	INFO:
*      	Lambert fragment shader.
*-----------------------------------------------------------------------------*/

#version 330

/*-----------------------------------------------------------------------------
*	IN/OUT
*-----------------------------------------------------------------------------*/
out vec4 g_outColor;

//INTERFACE BLOCKS
in VertexData {
	vec3 position;
	vec3 normal;									//normalized vector
	vec2 texCoord;
} VertexIn;

/*-----------------------------------------------------------------------------
*	UNIFORMS
*-----------------------------------------------------------------------------*/
uniform vec3				g_cameraDirection;		//normalized vector

//MATERIAL RELATED
//diffuse
uniform vec3				g_diffuseColor;
uniform sampler2D			g_diffuseMapSampler;
uniform bool				g_isDiffuseMapConnected;
//transparency
uniform vec3				g_transparencyColor;
uniform sampler2D			g_transparencyMapSampler;
uniform bool				g_isTransparencyMapConnected;
//ambient
uniform vec3				g_ambientColor;
uniform sampler2D			g_ambientMapSampler;
uniform bool				g_isAmbientMapConnected;

/*-----------------------------------------------------------------------------
*	FUNCTION DECLARATIONS
*-----------------------------------------------------------------------------*/
vec3 calcDefaultLight();
float calcLambertCosineFactor(vec3);

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
void main()
{
	/*-----------------------------------------------------------------------------
	*	CALCULATE TOTAL LIGHT
	*-----------------------------------------------------------------------------*/
	vec3 totalLight = vec3(0.0f, 0.0f, 0.0f);
	totalLight = calcDefaultLight();

	/*-----------------------------------------------------------------------------
	*	MATERIAL PROPERTIES
	*-----------------------------------------------------------------------------*/
	//CALCULATE DIFFUSE COLOR
	vec4 diffuseColor;
	diffuseColor = vec4(g_diffuseColor, 1.0f);

	//CALCULATE TRANSPARENCY COLOR
	vec4 transparencyColor;
	transparencyColor = vec4(g_transparencyColor, 1.0f);
	transparencyColor.a =
		(transparencyColor.r + transparencyColor.g + transparencyColor.b) / 3.0f;

	//CALCULATE AMBIENT COLOR
	vec4 ambientColor;
	ambientColor = vec4(g_ambientColor, 1.0f);

	/*-----------------------------------------------------------------------------
	*	OUTPUT COLOR
	*-----------------------------------------------------------------------------*/
	g_outColor = diffuseColor * (ambientColor + vec4(totalLight, 1.0f));
	
	//CALCULATE TRANSPARENCY
	if (g_isTransparencyMapConnected)
		g_outColor.a = transparencyColor.a;
	else
		g_outColor.a = 1.0f - transparencyColor.a;
}

/*-----------------------------------------------------------------------------
*	CALCULATE DEFAULT LIGHT
*-----------------------------------------------------------------------------*/
vec3 calcDefaultLight()
{
	vec3 defaultlLight = vec3(0.0f, 0.0f, 0.0f);

	float lambertCosineFactor = calcLambertCosineFactor(g_cameraDirection);
	if (lambertCosineFactor > 0)
		defaultlLight = vec3(1.0f, 1.0f, 1.0f) * lambertCosineFactor;

	//change range from <0.0, 1.0> to approximately <0.2, 0.8>
	defaultlLight = (defaultlLight / 1.65) + vec3(0.204, 0.204, 0.204);

	return defaultlLight;
}

/*-----------------------------------------------------------------------------
*	CALCULATE LAMBERT COSINE FACTOR
*-----------------------------------------------------------------------------*/
float calcLambertCosineFactor(vec3 rayDirection)
{
	return dot(VertexIn.normal, -rayDirection);
}
/*-----------------------------------------------------------------------------
*   SIMPLE USE
*-----------------------------------------------------------------------------*/
uniform vec3 g_color;

/*----------------------------------------------------------------------------*/

UniformVec3 color("g_color", vec3Value, spID)
{
    m_name =        "g_color";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

/*-----------------------------------------------------------------------------
*   SIMPLE ARRAY USE
*-----------------------------------------------------------------------------*/
uniform float g_color[3];

/*----------------------------------------------------------------------------*/

UniformVec3 colorRed("", floatValue, spID)
{
    m_name =        "";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

UniformVec3 colorGreen("", floatValue, spID)
{
    m_name =        "";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

...

UniformArray color("g_color");
{
    m_name = "g_color";
}
color.addUniform(colorRed, spID);
{
    location = gl::glGetUniformLocation(spID, m_name + "[" + m_uniformList.size() + "]");

    colorRed.setLocation(location);
    m_uniformList.push_back(colorRed);
}
color.addUniform(colorGreen, spID);
color.addUniform(colorBlue, spID);

/*-----------------------------------------------------------------------------
*   SIMPLE STRUCT USE
*-----------------------------------------------------------------------------*/
struct Light 
{
    vec3    color;
    float   intensity;
}

uniform Light g_light;

/*----------------------------------------------------------------------------*/

UniformVec3 color("color", vec3Val, spID);
{
    m_name =        "color";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

UniformFloat intensity("intensity", floatVal, spID);
{
    m_name =        "intensity";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

UniformStruct light("g_light");
{
    m_name = "g_light";
}
light.addUniform(color, spID);
{
    location = gl::glGetUniformLocation(spID, m_name + "." + color.getName());

    colorRed.setLocation(location);
    m_uniformList.push_back(colorRed);
}
light.addUniform(intensity, spID);

/*-----------------------------------------------------------------------------
*   ARRAY OF STRUCTURES USE
*-----------------------------------------------------------------------------*/
struct Light 
{
    vec3    color;
    float   intensity;
}

uniform Light g_light[2];

/*----------------------------------------------------------------------------*/

// STRUCT 1
UniformVec3 color1("color", vec3Val, spID);
{
    m_name =        "color";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

UniformFloat intensity1("intensity", floatVal, spID);
{
    m_name =        "intensity";
    m_location =    gl::glGetUniformLocation(spID, m_name);
}

UniformStruct light1("");
{
    m_name = "";
}
light1.addUniform(color1, spID);
{
    location = gl::glGetUniformLocation(spID, m_name + "." + color1.getName());

    color1.setLocation(location);
    m_uniformList.push_back(color1);
}
light1.addUniform(intensity1, spID);

// STRUCT 2
UniformVec3 color2("color", vec3Val, spID);
UniformFloat intensity2("intensity", floatVal, spID);

UniformStruct light2("");
light2.addUniform(color2, spID);
light2.addUniform(intensity2, spID);

// ARRAY
UniformArray lights("g_light");
{
    m_name = "g_light";
}
lights.addUniform(light1, spID);
{
    if (light1.getClassification() == Uniform::Classification::UNIT)
    {
        location = gl::glGetUniformLocation(spID, m_name + "[" + m_uniformList.size() + "]");
        light1.setLocation(location);
    }
    else if (light1.getClassification() == Uniform::Classification::CONTAINER)
    {
        baseName = m_name + "[" + m_uniformList.size() + "]";
        light1.findLocations(spID, baseName);
        {
            for (auto uniform : m_uniformList)
            {
                if (light1.getClassification() == Uniform::Classification::UNIT)
                {
                    location = gl::glGetUniformLocation(spID, baseName + "." + uniform.getName());
                    uniform.setLocation(location);
                }
                else if (light1.getClassification() == Uniform::Classification::CONTAINER)
                {
                    // for array
                    baseName = m_name + "[" + m_uniformList.size() + "]";
                    uniform.findLocations(spID, baseName);
                    {
                        ...
                    }

                    // for struct
                    baseName = m_name + "." + uniform.getName();
                    uniform.findLocations(spID, baseName);
                    {
                        ...
                    }
                }
            }
        }
    }

    m_uniformList.push_back(color1);
}

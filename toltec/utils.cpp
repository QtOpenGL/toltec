/*-----------------------------------------------------------------------------
*   CREATED:
*       16 IX 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "utils.hpp"

#include <fstream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>

/*-----------------------------------------------------------------------------
*   NAMESPACE: UTILS
*-----------------------------------------------------------------------------*/
namespace utils
{
    /*-----------------------------------------------------------------------------
    *   LOAD TEXT FILE
    *-----------------------------------------------------------------------------*/
    const std::string loadTextFile(const std::string& filePath, bool readLineByLineFlag)
    {
        std::ifstream file;
        file.open(filePath);

        if (file.is_open())
        {
            //READ LINE BY LINE
            if (readLineByLineFlag == true)
            {
                std::string outputString;
                std::string line;

                while (file.good())
                {
                    std::getline(file, line);
                    outputString.append(line + "\n");
                }

                return outputString;
            }
            //READ WHOLE FILE
            else
            {
                std::stringstream stream;
                stream << file.rdbuf();

                return stream.str();
            }
        }
        else
        {
            DEBUG_ERR("Unable to load a file: " << filePath << "!");
            return "";
        }
    }

    /*-----------------------------------------------------------------------------
    *   CALCULATE MODEL MATRIX
    *-----------------------------------------------------------------------------*/
    glm::mat4 calcModelMatrix(const glm::vec3& translation, const glm::vec3& rotation, 
        const glm::vec3& scale)
    {
        //TRANSLATION MATRIX
        glm::mat4 translationMatrix =   glm::translate(translation);

        //ROTATION MATRIX
        glm::mat4 rotationXMatrix =     glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotationYMatrix =     glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rotationZMatrix =     glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 rotationMatrix =      rotationZMatrix * rotationYMatrix * rotationXMatrix;

        //SCALE MATRIX
        glm::mat4 scaleMatrix =         glm::scale(scale);
        
        //MODEL MATRIX
        glm::mat4 modelMatrix =         translationMatrix * rotationMatrix * scaleMatrix;

        return modelMatrix;
    }

    /*-----------------------------------------------------------------------------
    *   ROTATE
    *   (const glm::vec3&, const glm::vec3&)
    *   Rotates given point along world coordinates by given x, y, z angles.
    *-----------------------------------------------------------------------------*/
    glm::vec3 rotate(const glm::vec3& point, const glm::vec3& xyzAngles)
    {
        glm::vec3 rotatedPoint3D = rotate(point, xyzAngles.x, xyzAngles.y, xyzAngles.z);
        return rotatedPoint3D;
    }

    /*-----------------------------------------------------------------------------
    *   ROTATE
    *   (const glm::vec3&, float, float, float)
    *   Rotates given point along world coordinates by given x, y, z angles.
    *-----------------------------------------------------------------------------*/
    glm::vec3 rotate(const glm::vec3& point, float xAngle, float yAngle, float zAngle)
    {
        //ROTATION MATRIX
        glm::mat4 rotationXMatrix =     glm::rotate(xAngle, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotationYMatrix =     glm::rotate(yAngle, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rotationZMatrix =     glm::rotate(zAngle, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 rotationMatrix =      rotationZMatrix * rotationYMatrix * rotationXMatrix;

        //ROTATE POINT
        glm::vec4 rotatedPoint4D =      rotationMatrix * glm::vec4(point, 0.0f);
        glm::vec3 rotatedPoint3D =      glm::vec3(rotatedPoint4D.x, rotatedPoint4D.y, rotatedPoint4D.z);

        return rotatedPoint3D;
    }

    /*-----------------------------------------------------------------------------
    *   ROTATE
    *   (const glm::vec3&, float, const glm::vec3&)
    *   Rotates given point along given rotation vector by given angle.
    *-----------------------------------------------------------------------------*/
    glm::vec3 rotate(const glm::vec3& point, float angle, const glm::vec3& rotationVector)
    {
        //SETUP QUATERNION
        glm::vec3 normalizedRotationVector =    glm::normalize(rotationVector);
        float w =                               glm::cos(angle / 2.0f);
        glm::vec3 v =                           glm::sin(angle / 2.0f) * normalizedRotationVector;
        glm::quat quaternion =                  glm::quat(w, v);

        //ROTATE POINT
        glm::vec3 rotatedPoint =                quaternion * point * glm::inverse(quaternion);

        return rotatedPoint;
    }
} //NAMESPACE: UTILS
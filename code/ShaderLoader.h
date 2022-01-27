#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H



/*
    Shader loader Class reads our shader programs from the file, 
    compiles them links them together in a Shader Program,
    the Program ID is stored in the class.
*/
#include "..\lib\glad\glad.h"  

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderLoader
{
    //Program Id
    unsigned int shaderID;
    ShaderLoader();
 
    void Init(const char* vertexPath, const char* fragmentPath);

    //use/activate the shader
    void use();

    //utility uniform functions
    void setUniBool(const std::string &name, bool value) const;
    void setUniInt(const std::string &name, int value) const;
    void setUniFloat(const std::string &name, float value) const;
    void setUniMat4(const std::string & name, glm::mat4 value) const;
    void setUniVec2(const std::string & name, glm::vec2 value) const;
};
 

#endif
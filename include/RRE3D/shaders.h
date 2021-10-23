#ifndef SHADERS_CLASS_H
#define SHADERS_CLASS_H

class Shader
{
    GLuint shaderProgram;
    VertexShader vertexShader;
    FragmentShader fragmentShader;

    Shader(VertexShader vShader, FragmentShader fShader)
    {
        shaderProgram = glCreateProgram();
        vertexShader = vShader;
        fragmentShader = fShader;
    }
};

class VertexShader
{

};

class FragmentShader
{

};

#endif
#include "GLFW/glfw3.h"
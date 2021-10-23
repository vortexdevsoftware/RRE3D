#ifndef SHADERS_CLASS_H
#define SHADERS_CLASS_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Shader
{
    GLuint shaderProgram;

    Shader(const char *vShader, const char *fShader)
    {
        GLuint vertex;
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShader, NULL);
        glCompileShader(vertex);

        GLuint frag;
        frag = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(frag, 1, &fShader, NULL);
        glCompileShader(frag);

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertex);
	    glAttachShader(shaderProgram, frag);
	    glLinkProgram(shaderProgram);

        glDeleteShader(vertex);
	    glDeleteShader(frag);
    }
};

#endif
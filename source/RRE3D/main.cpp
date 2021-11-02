#define STB_IMAGE_IMPLEMENTATION

#include "rre3d.h"

///// PRE DEFINED VARIABLES ////

// Time
float deltaTime;
float Time;
//

///// ENTRY POINT /////

/* This is the true starting point of the application */
int main(void)
{
    /* The 3D renderer window of the application */
    GLFWwindow* window; 

    if(!glfwInit())
      return 1;

    /* Use OpenGL 4.6 */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 800, "RRE3D", NULL, NULL);
    if (window == nullptr){
		   glfwTerminate();
  		 return 1;
	  }

    GLuint arroz;
    
    glfwMakeContextCurrent(window);
    gladLoadGL();
  	glViewport(0, 0, 800, 800);

    /* Once everything is ready, call the Start function just before the main loop */
    RRE3D::Start();

    double lastTime = glfwGetTime();
    /* The main loop, which keeps the application open */
    while(!glfwWindowShouldClose(window))
    {
        /* Time */

        double nowTime = glfwGetTime();
        Time = nowTime;
        deltaTime = (nowTime - lastTime);
        lastTime = nowTime;

        /* Debugging delta time */
        glfwSetWindowTitle(window, ("Delta Time: " + std::to_string(deltaTime)).c_str());

        /* Time */

        /* Call the Update function that is defined by the user in their application environment */
        RRE3D::Update();

        glClearColor(0.2, 0.4, 0.243, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
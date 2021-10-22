#include "RRE3D/rre3d.h"
#include "GLFW/glfw3.h"

/* This is the true entry point of the application */
int main()
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
    if (!window){
		   glfwTerminate();
  		 return 1;
	  }
    
    glfwMakeContextCurrent(window);

    /* Once everything is ready, call the first function just before the main loop */
    //RRE3D::Start();

    /* The main loop, which keeps the application open */
    while(!glfwWindowShouldClose(window))
    {
        //RRE3D::Update();
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

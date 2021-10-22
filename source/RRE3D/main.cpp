#include "RRE3D/rre3d.h"
#include "GLFW/glfw3.h"

/* Time */
float timestep = 1.0 / 60.0;
float deltaTime;
float Time;
/* Time */

/* This is the true entry point of the application */
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
    
    glfwMakeContextCurrent(window);

    /* Once everything is ready, call the first function just before the main loop */
    RRE3D::Start();

    double lastTime = glfwGetTime();
    /* The main loop, which keeps the application open */
    while(!glfwWindowShouldClose(window))
    {
        /* Time */

        double nowTime = glfwGetTime();
        Time = nowTime;
        deltaTime += (nowTime - lastTime) / timestep;
        lastTime = nowTime;

        while (deltaTime >= 1.0){
            RRE3D::FixedUpdate();   // - FixedUpdate function
            deltaTime--;
        }

        /* Time */

        RRE3D::Update();
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

/* Changes the timestep Ex: 0.0166*/
void RRE3D::ChangeTimestep(float tstep)
{ 
    timestep = tstep;
}

/* Changes the timestep Ex: 60 (Called 60 times per frame) */
void RRE3D::ChangeTimestep(float frames)
{
    timestep = 1.0 / frames;
}

#include "gl_invade.h"


bool running = true;


void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        running = false;
    }
}



int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create Our window
    GLFWwindow* window = glfwCreateWindow(800,800, "Invade",0,0);

    if(!window)
    {
        puts("Failed to create Opengl window\n");
        return -1; 
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        puts("Failed to initialize GLAD\n");
        return -1;
    }

    while(running)
    {   
        processInput(window);
        
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;

}



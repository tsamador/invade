
#include "gl_invade.h"


bool running = true;
GLFWwindow* window;

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create Our window
    window = glfwCreateWindow(800,800, "Invade",0,0);

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

    InvadeMainLoop();

    glfwTerminate();

    return 0;

}

//TODO(Tanner) Maybe pass this as a pointer??
void Render(game_state* gameState)
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    gameState->shader->use();
    //gameState->shader->setUniFloat("yOffset", gameState->ship->yOffset);
    //gameState->shader->setUniFloat("xOffset", gameState->ship->xOffset);
    glBindVertexArray(gameState->ship->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
}


void ProcessInput(game_state* gameState)
{
    gameState->input = {};

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        gameState->active = false;
    }

    if(glfwGetKey(window,GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        gameState->input.left = true;
    }

    if(glfwGetKey(window,GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        gameState->input.right = true;
    }

    if(glfwGetKey(window,GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        gameState->input.space = true;
    }
}

int CreateVAO(float* vertices, int verticesSize)
{
    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,verticesSize, vertices, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    //TODO(Tanner) add Texture coordinates to 

    return VAO;
}





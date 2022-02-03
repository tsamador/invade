
#include "gl_invade.h"

GLFWwindow* window;
glm::mat4 projection;

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
    UpdateGameStateWindow(width, height);
    glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);  
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create Our window
    window = glfwCreateWindow(800,800, "Invade",0,0);

    //Setup our projection matrix
    projection = glm::ortho(0.0f, 800.0f, 800.0f, 0.0f, -1.0f, 1.0f);  

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

void Render(game_state* gameState)
{
    /*TODO(Tanner): I don't really need to set this uniform every render call, 
    only whenever the window changes. 
    */
    gameState->shader->setUniMat4("projection", projection);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    /* First, Render our ship */
    glm::mat4 model = glm::mat4(1.0);
    // First Translate

    /*Note(Tanner): I was wondering what the advantage is for us
    to create the matrix on the CPU as opposed to on the shader,but the
    reason is we don't want to recompute this model matrix per vertex,
    we would essentially at least triple the work per object.*/
    model = glm::translate(model, gameState->ship->pos);

    /* Now Rotate (Uneeded for this project)*/

    /* Finally, Scale */
    model = glm::scale(model, gameState->ship->size);

    gameState->shader->use();    
    gameState->shader->setUniMat4("model", model);

    glBindVertexArray(gameState->ship->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    
    /* FINISHED DRAWING SHIP */

    /* NOW RENDER SHIPS BULLETS */
    gameState->shader->setUniMat4("model", glm::mat4(1.0f));

    glBindVertexArray(gameState->ship->bulletVAO);
    glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_INT, 0);

    /* Now Render our enemies */
    glBindVertexArray(gameState->EnemyVAO);

    
    Enemy* enemiesArr = gameState->enemies.enemies;
    for(int i = 0; i < 10; i ++)
    {
        model = glm::mat4(1.0);
        model = glm::translate(model, enemiesArr[i].pos);
        model = glm::scale(model, enemiesArr[i].size);

        gameState->shader->setUniMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    
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

    //TODO(Tanner) add Texture coordinates to This function

    return VAO;
}
//Similar to above but creates a VAO besed upon vertices and indices
int CreateIndicesVAO(float* vertices, int verticesSize, unsigned int* indices, int indicesSize)
{
    //set up our vertex buffers
    unsigned int VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    //Create our buffer on the GPU and Send our vertices to it.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices,  GL_STATIC_DRAW);

    //Create our buffer on the GPU and send our indices to it.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    return VAO;
}
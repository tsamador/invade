#ifndef ENTITY_H
#define ENTITY_H

#include "ShaderLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


struct position {
    int x;
    int y;
};

struct Entity
{
    int VAO;
    glm::vec3 pos;
    glm::vec3 size;
    bool alive;
};

#endif
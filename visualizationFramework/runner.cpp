#include "runner.h"
#include <GLFW/glfw3.h>

//Constructor
Runner::Runner()
{
    std::cout << "Hello world 2" << std::endl;

    if(glfwInit()) std::cout << "GLFW initialized" << std::endl;
}

//Destructor
Runner::~Runner()
{
}
    
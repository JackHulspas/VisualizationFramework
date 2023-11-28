#include <visualizationFramework/runner.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Main function
int main(void) {
    std::cout << "Main method called" << std::endl;
    Runner runner;

    do { //Start running the application
        runner.run();
    } while (glfwGetKey(runner.getRenderer()->getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(runner.getRenderer()->getWindow()) == 0); //Closes the application whene the window is closed (by pressing ESC or closing the window manually)

    glfwTerminate();

    return 0;
}
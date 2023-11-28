#include "runner.h"

//Constructor
Runner::Runner() {
    std::cout << "Runner constructed" << std::endl;
    renderer = new Renderer(1920, 1080, "Visualization framework");
}

//Destructor
Runner::~Runner() {
    std::cout << "Runner de-constructed" << std::endl;
    delete renderer;
}

void Runner::run() {
    //Render the window
    renderer->renderWindow();
}

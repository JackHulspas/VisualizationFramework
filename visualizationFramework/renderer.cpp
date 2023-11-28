#include "renderer.h"

//Constructor
Renderer::Renderer(unsigned int width, unsigned int height, std::string windowName) {
    std::cout << "Runner constructed" << std::endl;

    //Assign window resolution
    windowWidth_ = width;
    windowHeight_ = height;
    windowName_ = windowName;

    //Initialize the renderer
    this->initialize();
}

// Destructor
Renderer::~Renderer() {
    std::cout << "Runner de-constructed" << std::endl;
}

//Render the window
void Renderer::renderWindow() {
    //Set the background to dark blue
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f); 
    glClear(GL_COLOR_BUFFER_BIT);

    //Swap buffers and poll events
    glfwSwapBuffers(window_);
    glfwPollEvents();   
}

//Initialize the renderer
int Renderer::initialize() {
    //Initialize GLFW and set the version to 3.3
    if(!glfwInit()) { //If GLFW doesn't initialize, stop the process
        std::cout << "Failed to initialize FLGW library \n" << std::endl;
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We explicitly want to use the core-profile
    
    /*
    //If you are on Mac OS X you must uncomment this line
    //However this framework is designed to be compatible for Windows and Linux,
    //so be aware that Mac OS X users may run into other issues that aren't adressed in this framework 

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    */

    //Open a windoww and create its OPENGL context, passing along the resolution and window name
    //Pass in the primary monitor to make the window fullscreen, if you want the application to be windowed: replace glfwGetPrimaryMonitor() with NULL
    window_ = glfwCreateWindow(windowWidth_, windowHeight_, windowName_.c_str(), glfwGetPrimaryMonitor(), NULL);
    if (window_ == NULL) { //If the window fails to get created, stop the process
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window_); //Make the context of our window the main context on the current thread

    //Load GLAD by passing the function to load the adress of the (OS-specific) OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { //If GLAD fails to load, stop the process
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    //Let OpenGL know the size of the rendering window, so it knows how to display the data and coordinates with respect to the window
    //We can, if we want to, make this value smaller than the window height, allowing us to use the remaining space for other elements
    //However, for our current use-case, this will do just fine
    glViewport(0, 0, windowWidth_, windowHeight_);

    return 0;
}

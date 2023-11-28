/**
 * @file renderer.h
 *
 * @brief The Renderer header file.
 *
 * This file is part of visualizationFramework, a 3D OpenGL framework.
 *
 * - Copyright 2023 Jack Hulspas
 *   - Initial commit
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Renderer {
	public:
		///@brief Constructor of the Runner.
		Renderer(unsigned int width, unsigned int height, std::string windowName);

		///@brief Constructor of the Runner.
		virtual ~Renderer();

		///@brief Renders the window.
		///@return void
		void renderWindow();

		///@brief Gets the application window.
		///@return GLFWwindow* window
		GLFWwindow* getWindow() { return window_; };

	private:
		///@brief Intializes the renderer and the application window.
		///@return int
		int initialize();

		///@brief The application window.
		GLFWwindow* window_;

		///@brief The width of the application window.
		unsigned int windowWidth_;

		///@brief The height of the application window.
		unsigned int windowHeight_;

		///@brief The name of the application window.
		std::string windowName_;
};

#endif /* RENDERER_H */
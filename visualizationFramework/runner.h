/**
 * @file runner.h
 *
 * @brief The Runner header file.
 *
 * This file is part of visualizationFramework, a 3D OpenGL framework.
 *
 * - Copyright 2023 Jack Hulspas
 *   - Initial commit
 */

#ifndef RUNNER_H
#define RUNNER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <visualizationFramework/renderer.h>

class Runner {
	public:
		///@brief Constructor of the Runner.
		Runner();

		///@brief Constructor of the Runner.
		virtual ~Runner();

		///@brief Runs the specified scene.
		///@return void
		void run();

		///@brief Gets the renderer.
		///@return Renderer* renderer
		Renderer* getRenderer() { return renderer; }

	private:
		Renderer* renderer;
};

#endif /* RUNNER_H */
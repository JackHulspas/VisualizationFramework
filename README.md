# VisualizationFramework
A complete rework of one of my old projects. This project is a framework for 3D visualization created with OpenGL.
As opposed to the original version of this project, this one will be created with professional standards in mind. The original project had a class diagram, code documentation created with DoxyGen, design documents and good coding practices. This version will also include unit tests and overall improved code quality.

# Project introduction
The vision for this project is to make a 3D visual framework. The end-user will be able to use this framework to render 3D visuals in real time. The framework will render shadows and simulate simple collision and physics.
The end-user will be able to import their own textures and 3D models. The end-user will be able to create their own scene, with its own camera.
The framework will be designed with upgradability in mind. After the core features are implemented, new features could be implemented. Some of the features I plan to add after the core features are implemented are: Procedural generation, terrain generation, marching cubes, perlin/simplex noise, and custom file loaders.
The framework will be designed with a logical and expandable structure.

![FrameworkUMLDiagram](https://github.com/JackHulspas/VisualizationFramework/assets/136746358/7cec2ab7-1aca-4b89-b7eb-583a5f821a99)

The 3D visualization framework is designed to be used with Windows and Linux.

# Documentation
To generate the documentation for the framework, run doxygen (with Doxyfile as input) in the root directory of this project:
``` doxygen Doxyfile ```
Afterwards, open documentation.html in the doc directory

Within the docs directory you cal also find both the DOCX and PDF files for the project documents

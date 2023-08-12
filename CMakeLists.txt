# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (VisualizationFramework)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(VisualizationFramework REGULAR_EXPRESSION ".*/visualizationFramework/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

link_directories( # g++ -Lpath/to/library

)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	#glfw
	#GLEW_190
)

# MyFramework (libvisualizationFramework.a)
add_library(visualizationFramework # ar rcs libvisualizationFramework.a
	visualizationFramework/runner.h
	visualizationFramework/runner.cpp
)

# Main
add_executable(main # g++ demo/main.cpp -o main
	demo/main.cpp
)
target_link_libraries(main # g++ -lvisualizationFramework
	visualizationFramework
	${ALL_GRAPHICS_LIBS}
)

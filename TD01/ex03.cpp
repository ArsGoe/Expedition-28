#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "glbasimac/glbi_engine.hpp"
#include <iostream>

using namespace glbasimac;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;
static float aspectRatio = 1.0f;

/* OpenGL Engine */
GLBI_Engine myEngine;

/* Espace virtuel */
static const float GL_VIEW_SIZE = 1.;
// L'univers 2D visible a une taille de 1.0 en x et en y

void onWindowResized(GLFWwindow* /*window*/, int width, int height){
	aspectRatio = width / (float) height;
	//définit la taille en pixels de la (sous) fenêtre où sera dessinée réellement notre scène OpenGL
	glViewport(0, 0, width, height);
	if( aspectRatio > 1.0){
		//Défini, suivant la taille de la fenêtre (aspectRatio), les coordonnées de l’univers visible en 2D grâce à une projection orthogonale 2D
		myEngine.set2DProjection(-GL_VIEW_SIZE * aspectRatio/ 2.,
		GL_VIEW_SIZE * aspectRatio / 2. ,
		-GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
	}
	else{
		myEngine.set2DProjection(-GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
		-GL_VIEW_SIZE / (2. * aspectRatio),
		GL_VIEW_SIZE / (2. * aspectRatio));
	}
}

/* Error handling function */
void onError(int error, const char* description) {
	std::cout << "GLFW Error ("<<error<<") : " << description << std::endl;
}

int main() {
    // Initialize the library
    if (!glfwInit()) {
        return -1;
    }

    /* Try to uncomment this for Mac if it did not work */
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    /* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

    // Create a windowed mode window and its OpenGL context
    //permet d’ouvrir une fenêtre et de fixer ses paramètres
    //longueur, largeur, title, monitor (créer un fenêtre fullscreen) et share (partager un contexte avec d’autres fenêtres)
    GLFWwindow* window = glfwCreateWindow(800, 800, "TD 01 Ex 03", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

	//Permet de redimensionner la fenêtre
	glfwSetWindowSizeCallback(window,onWindowResized);

    // Make the window's context current
    glfwMakeContextCurrent(window);

	// Intialize glad (loads the OpenGL functions)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	// Initialize Rendering Engine
	myEngine.initGL();


	onWindowResized(window,800, 800);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Render here */
		glClearColor(0.2f,0.f,0.f,0.f);
		glClear(GL_COLOR_BUFFER_BIT);

        // render here

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/* Elapsed time computation from loop begining */
		double elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		while(elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS-elapsedTime);
			elapsedTime = glfwGetTime() - startTime;
		}
	}

    glfwTerminate();
    return 0;
}

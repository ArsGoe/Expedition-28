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

/* Variables */
double xpos, ypos;
int height, width;
float r,g,b;
bool mode1{true};

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

/*Fermer fenêtre */
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key== GLFW_KEY_Q && action == GLFW_PRESS){ //en clavier Qwerty, donc a pour nous
        glfwSetWindowShouldClose(window, true);
    }
	if (key== GLFW_KEY_E && action == GLFW_PRESS){ //en clavier Qwerty, donc a pour nous
		mode1 = !mode1;
		if (!mode1){
			r = 0;
			g = 0;
			b = 0;
		}
    }
	if (mode1 == false){
		if (key==GLFW_KEY_R && action == GLFW_PRESS && mods != GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			r = r+0.1;
    	}
		else if (key==GLFW_KEY_G && action == GLFW_PRESS && mods != GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			g = g+0.1;
    	}
		else if (key==GLFW_KEY_B && action == GLFW_PRESS && mods != GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			b = b+0.1;
    	}
		else if (key==GLFW_KEY_R && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			r = r-0.1;
    	}
		else if (key==GLFW_KEY_G && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			g = g-0.1;
    	}
		else if (key==GLFW_KEY_B && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT){ //en clavier Qwerty, donc a pour nous
			b = b-0.1;
    	}
	}
}

/* Changer la couleur clique*/

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
		if (mode1 == true){
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
			glfwGetCursorPos(window, &xpos, &ypos);

			int x = (int)xpos;
			int y = (int)ypos;

			r = (x % 256) / 255.0f;
			g = (y % 256) / 255.0f;

			}
		}
}

//Changer la couleur position souris

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
		if (mode1 == true){
			glfwGetCursorPos(window, &xpos, &ypos);
			glfwGetWindowSize(window, &width, &height);

			r = xpos / width;
			b = ypos / height;
		}
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

	onWindowResized(window,800, 800); //Permet d'initialiser la fênetre
	//Comme ça se sert de GL et engine, on le place après avoir init ces deux éléments

	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//Bouge souris
	glfwSetCursorPosCallback(window, cursor_position_callback);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

        //glClearColor(r, g, 0.0f, 1.0f);

		/* Render here */
		glClearColor(r,g,b,0.f);
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

		glfwSetKeyCallback(window, key_callback);
	}

    glfwTerminate();
    return 0;
}

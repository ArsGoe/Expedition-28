#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/shaders.hpp"
#include <iostream>
#include <string>

using namespace glbasimac;
using namespace STP3D;

/* Variables */
double xpos, ypos;

/* Window properties */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "TD02 Ex04";
static float aspectRatio = 1.0f;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* Virtual windows space */
static const float GL_VIEW_SIZE = 4.;

/* OpenGL Engine */
GLBI_Engine myEngine;
GLBI_Set_Of_Points thePoints;
GLBI_Convex_2D_Shape triangle;
GLBI_Convex_2D_Shape cercle;
GLBI_Convex_2D_Shape carre;

/* Error handling function */
void onError(int error, const char* description) {
	std::cout << "GLFW Error ("<<error<<") : " << description << std::endl;
}

void onWindowResized(GLFWwindow* /*window*/, int width, int height)
{
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;
	aspectRatio = width / (float) height;

	glViewport(0, 0, width, height);
	if( aspectRatio > 1)
	{
		myEngine.set2DProjection(-GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio,
								 -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
	}
	else
	{
		myEngine.set2DProjection(-GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
								 -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
	}
}

int i = 0;
void onKey(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	std::vector<int> nature {GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN};
	if (key == GLFW_KEY_V && action == GLFW_PRESS) {
		if (i >= 7){
			i = 0;
			thePoints.changeNature(nature[i]);
		}
		else {
			i++;
			thePoints.changeNature(nature[i]);
		}
	}
}

void initScene() {
	//std::vector<float> points = {0.0, 0.0, 0.5f, 0.0f, 0.0f, 0.5f, -0.5, -0.5};
	//std::vector<float> couleurs = {0.0,0.0,0.0, 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0};
	//thePoints.initSet(points,couleurs);
	//std::vector<float> pointsCarre = {-0.5, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5};
	//std::vector<float> pointsTriangle = {-0.5, -0.5, 0.5, -0.5, 0.0, 0.5};
	//triangle.changeNature(GL_TRIANGLES);
	//triangle.initShape(pointsTriangle);
	std::vector<float> pointsCercle= {};
	float tourDeCercle = 2*M_PI / 100;
	for (i = 0; i < 100; i++){
		pointsCercle.push_back(cos(tourDeCercle * i));
		pointsCercle.push_back(sin(tourDeCercle * i));
	}
	cercle.changeNature(GL_TRIANGLE_FAN);
	cercle.initShape(pointsCercle);
}

void renderScene() {
	glClearColor(1.0f,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	thePoints.drawSet();
	//carre.drawShape();

	myEngine.setFlatColor(0.0,1.0,0.0); //Change la couleur des prochaines formes
	//triangle.drawShape();
	cercle.drawShape();
}

/* Souris*/
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		glfwGetCursorPos(window, &xpos, &ypos);
		//Conversion si on est à l'horizontal
		if( aspectRatio > 1){
			xpos = (xpos - (WINDOW_WIDTH / 2)) * GL_VIEW_SIZE / WINDOW_HEIGHT;
			ypos = -(ypos - (WINDOW_HEIGHT / 2)) * GL_VIEW_SIZE / WINDOW_HEIGHT;
		}
		//Conversion si on est à la vertical
		else {
			xpos = (xpos - (WINDOW_WIDTH / 2)) * GL_VIEW_SIZE / WINDOW_WIDTH;
			ypos = -(ypos - (WINDOW_HEIGHT / 2)) * GL_VIEW_SIZE / WINDOW_WIDTH;
		}
		std::vector<float> sourisPosition ={(float)xpos, (float)ypos};
		std::vector<float> sourisCouleur = {0.5,0.5,0.5};
		thePoints.addAPoint(sourisPosition.data(), sourisCouleur.data());
	}
}

int main(int /*argc*/, char** /*argv*/)
{
	/* GLFW initialisation */

	GLFWwindow* window;
	if (!glfwInit()) return -1;


    /* Try to uncomment this for MAC OS if it did not work */
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		// If no context created : exit !
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	std::cout<<"Loading GL extension"<<std::endl;
	// Intialize glad (loads the OpenGL functions)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	glfwSetWindowSizeCallback(window,onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	std::cout<<"Engine init"<<std::endl;
	myEngine.initGL();
	onWindowResized(window,WINDOW_WIDTH,WINDOW_HEIGHT);
	CHECK_GL;

	//	void initSet(std::vector<float> in_coord,float c_r,float c_v,float c_b);
	// Avant de dessiner mais après la mise en place de Open GL
	initScene();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Render here */

		renderScene();

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

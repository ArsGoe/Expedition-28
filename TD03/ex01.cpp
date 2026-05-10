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
int vitesse = 1;
int angle = 0;
int beta = -60;

/* Window properties */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "TD02 Ex04";
static float aspectRatio = 1.0f;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* Virtual windows space */
static const float GL_VIEW_SIZE = 200.;

/* OpenGL Engine */
GLBI_Engine myEngine;
GLBI_Convex_2D_Shape cercle;
GLBI_Convex_2D_Shape carre;
GLBI_Convex_2D_Shape trapeze;
GLBI_Convex_2D_Shape rectangle;

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
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    if (key == GLFW_KEY_P && action == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
}

void initScene() {
	//std::vector<float> points = {0.0, 0.0, 0.5f, 0.0f, 0.0f, 0.5f, -0.5, -0.5};
	//std::vector<float> couleurs = {0.0,0.0,0.0, 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0};
	//thePoints.initSet(points,couleurs);

	std::vector<float> pointsCarre = {-0.5, 0.5, 0.5, 0.5, 0.5, -0.5, -0.5, -0.5};
	// std::vector<float> pointsTriangle = {-0.5, -0.5, 0.5, -0.5, 0.0, 0.5};
	carre.initShape(pointsCarre);
	carre.changeNature(GL_TRIANGLE_FAN);
	
    std::vector<float> pointsRectangle = {-0.4, 0.5, 0.4, 0.5, 0.4, -0.5, -0.4, -0.5};
	// std::vector<float> pointsTriangle = {-0.5, -0.5, 0.5, -0.5, 0.0, 0.5};
	rectangle.initShape(pointsRectangle);
	rectangle.changeNature(GL_TRIANGLE_FAN);

    std::vector<float> pointsTrapeze = {0, 20, 60, 10, 60, -10, 0, -20};
    trapeze.changeNature(GL_TRIANGLE_FAN);
    trapeze.initShape(pointsTrapeze);

	std::vector<float> pointsCercle= {};
	float tourDeCercle = 2*M_PI / 100;
	for (i = 0; i < 100; i++){
		pointsCercle.push_back(cos(tourDeCercle * i));
		pointsCercle.push_back(sin(tourDeCercle * i));
	}
	cercle.changeNature(GL_TRIANGLE_FAN);
	cercle.initShape(pointsCercle);
}

void drawFirstArm() {
	myEngine.setFlatColor(0.0,1.0,0.0);
	myEngine.updateMvMatrix();
    trapeze.drawShape();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D homothetie{20,20,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie);

		myEngine.setFlatColor(1.0,0.0,0.0); //Change la couleur des prochaines formes
		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr{60.0,0,0.0};
    	myEngine.mvMatrixStack.addTranslation(tr);

		Vector3D homothetie2{10.0,10.0,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie2);

		myEngine.setFlatColor(0.0,0.0,1.0); //Change la couleur des prochaines formes
		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}

void drawRoundedSquare() {

	//Rectangle vertical
	myEngine.setFlatColor(1.0,1.0,0.0);
	myEngine.updateMvMatrix();
	rectangle.drawShape();

	//Rectangle Horizontal
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D rotation{0.0,0.0,1.0};
		myEngine.mvMatrixStack.addRotation(M_PI/2, rotation);

		myEngine.updateMvMatrix();
		rectangle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
	
	//Cercle 1
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr{0.4,0.4,0.0};
    	myEngine.mvMatrixStack.addTranslation(tr);

		Vector3D homothetie{0.1,0.1,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie);

		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//Cercle 2
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr2{0.4,-0.4,0.0};
    	myEngine.mvMatrixStack.addTranslation(tr2);

		Vector3D homothetie2{0.1,0.1,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie2);

		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//Cercle 3
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr3{-0.4,-0.4,0.0};
    	myEngine.mvMatrixStack.addTranslation(tr3);

		Vector3D homothetie3{0.1,0.1,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie3);

		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	//Cercle 4
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr4{-0.4,0.4,0.0};
    	myEngine.mvMatrixStack.addTranslation(tr4);

		Vector3D homothetie4{0.1,0.1,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie4);

		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();

}

void drawSecondArm() {
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D homothetie2{10,10,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie2);
		drawRoundedSquare();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr6{40,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr6);

		Vector3D homothetie4{10,10,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie4);
		drawRoundedSquare();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr5{20,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr5);

		Vector3D homothetie3{46,6,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie3);

		myEngine.setFlatColor(1.0,0.5,1.0);
		myEngine.updateMvMatrix();
		carre.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}

void drawThirdArm() {
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D homothetie1{6,6,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie1);

		myEngine.setFlatColor(0.5,0.5,0.0);
		myEngine.updateMvMatrix();
		carre.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr1{18,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr1);

		Vector3D homothetie2{40,4,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie2);

		myEngine.setFlatColor(0.5,0.9,0.3);
		myEngine.updateMvMatrix();
		carre.drawShape();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr2{38,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr2);

		Vector3D homothetie3{4,4,1.0};
		myEngine.mvMatrixStack.addHomothety(homothetie3);

		myEngine.setFlatColor(0.2,0.8,0.7);
		myEngine.updateMvMatrix();
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}

void renderScene() {

	myEngine.mvMatrixStack.loadIdentity();
	glClearColor(1.0f,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	//thePoints.drawSet();
	//carre.drawShape();

	//Cercle
	myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr1Bras{-60,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr1Bras);

		angle += vitesse;
		if (angle > 45) {
				vitesse = -1;
		}
		else if (angle < -45){
				vitesse = 1;
		}


		Vector3D rotation1Bras{0.0,0.0,1.0};
		myEngine.mvMatrixStack.addRotation(deg2rad(angle), rotation1Bras);

		myEngine.setFlatColor(1.0,0.0,0.0); //Change la couleur des prochaines formes
		drawFirstArm();

		//Deuxième bras

		Vector3D tr2Bras{60,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr2Bras);
		
		Vector3D rotation2Bras{0.0,0.0,1.0};
		myEngine.mvMatrixStack.addRotation(deg2rad(beta), rotation2Bras);

		drawSecondArm();
	//myEngine.mvMatrixStack.popMatrix();

	//myEngine.mvMatrixStack.pushMatrix();
		Vector3D tr3Bras{40,0,0.0};
		myEngine.mvMatrixStack.addTranslation(tr3Bras);
		drawThirdArm();

		Vector3D rotation3Bras{0.0,0.0,1.0};
		myEngine.mvMatrixStack.addRotation(deg2rad(45), rotation3Bras);
		drawThirdArm();
		//Vector3D rotation3Bras{0.0,0.0,1.0};
		//myEngine.mvMatrixStack.addRotation(deg2rad(35), rotation3Bras);

		myEngine.mvMatrixStack.addRotation(deg2rad(-90), rotation3Bras);
		drawThirdArm();
	myEngine.mvMatrixStack.popMatrix();
}

/* Souris*/
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		beta = beta + 5;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
		beta = beta - 5;
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

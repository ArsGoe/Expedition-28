#include "draw_scene.hpp"
#include "draw_gare_batiment.hpp"
#include "draw_train.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;

IndexedMesh* cylinder;
GLBI_Convex_2D_Shape cercle{3};
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};

/***************************************** Déclaration formes gare *****************************************/

void initAxes(){
	//X EN ROUGE
	std::vector<float> points_x {0.0, 0.0, 0.0,
								10.0, 0.0, 0.0};
	std::vector<float> points_color_x {1.0, 0.0, 0.0,
								1.0, 0.0, 0.0};
	x.initSet(points_x,points_color_x);
	x.changeNature(GL_LINES);

	//Y EN VERT
	std::vector<float> points_y {0.0, 0.0, 0.0,
								0.0, 10.0, 0.0};
	std::vector<float> points_color_y {0.0, 1.0, 0.0,
										0.0, 1.0, 0.0};
	y.initSet(points_y,points_color_y);
	y.changeNature(GL_LINES);

	//Z EN BLEU
	std::vector<float> points_z {0.0, 0.0, 0.0,
								0.0, 0.0, 10.0};
	std::vector<float> points_color_z {0.0, 0.0, 1.0,
										0.0, 0.0, 1.0};
	z.initSet(points_z,points_color_z);
	z.changeNature(GL_LINES);
}

void initCylinder(){
	cylinder = basicCylinder(1.0, 1.0);
	cylinder->createVAO();

	int nbPointDuCercle { 100 };
	int rayon { 1 };
	std::vector<float> initCercle {};
	for(int i { 0 }; i < nbPointDuCercle; i++) {
		float angle = 2 * M_PI * i / nbPointDuCercle;
		initCercle.push_back(sin(angle) * rayon);
		initCercle.push_back(0.0f);
		initCercle.push_back(cos(angle) * rayon);
	}

	cercle.initShape(initCercle);
	cercle.changeNature(GL_TRIANGLE_FAN);
}

void initCube(){
	cube = basicCube(1.0f);
	cube->createVAO();
}

void initScene() {
	initAxes();
	initCylinder();
	initCube();
	initSphere();
}

void drawCylindreFerme() {
	//myEngine.setFlatColor(1.0, 0.0, 0.0);
	cercle.drawShape();
	//myEngine.setFlatColor(1.0, 1.0, 1.0);
	cylinder->draw();

	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({ 0.0f, 1.f, 0.0f }); // Correction de la taille
		myEngine.updateMvMatrix();

		//myEngine.setFlatColor(1.0, 0.0, 0.0); // Conversion des couleurs en [0, 1]
		cercle.drawShape();

	myEngine.mvMatrixStack.popMatrix();
}

void axes(){
	x.drawSet();
	y.drawSet();
	z.drawSet();
}

void drawScene() {
	axes();
	drawGare();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({ 0.0f, 15.f, 0.0f });
		myEngine.mvMatrixStack.addHomothety({ 0.3f, 0.3f, 0.3f });
		myEngine.updateMvMatrix();

		drawTrain();

	myEngine.mvMatrixStack.popMatrix();
}




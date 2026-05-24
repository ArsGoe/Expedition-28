#include "draw_scene.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};

/***************************************** Déclaration formes gare *****************************************/
IndexedMesh* cube;
IndexedMesh* sphere;

void initScene() {
	std::vector<float> points {0.0,0.0,0.0};
	somePoints.initSet(points,1.0,1.0,1.0);

	std::vector<float> baseCarre{-10.0,-10.0,0.0,
								 10.0,-10.0,0.0,
								 10.0,10.0,0.0,
								 -10.0,10.0,0.0};
	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);

	cube = basicCube(1.0);
	cube->createVAO();

	sphere = basicCylinder(1.0f, 1.0f);
	sphere->createVAO();
}

/***************************************** Déclaration formes gare *****************************************/

void drawScene() {
/* 	glPointSize(10.0);

	somePoints.drawSet();

	myEngine.setFlatColor(0.2,0.0,0.0);
	ground.drawShape();
 */
	//Gare
	/* myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addHomothety({20.f, 15.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(124.0f/255.0f, 136.0f/255.0f, 132.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); */

	//Fenêtre
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.setFlatColor(124.0f/255.0f, 136.0f/255.0f, 132.0f/255.0f);
		sphere->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}




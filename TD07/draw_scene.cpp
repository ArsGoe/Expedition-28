#include "draw_scene.hpp"
#include "tools/basic_mesh.hpp"
#include "tools/vector3d.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;

IndexedMesh* cylinder;
GLBI_Convex_2D_Shape cercle{3};
GLBI_Convex_2D_Shape sides{3};
GLBI_Convex_2D_Shape sides_mais{3};
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};

float rr = 0.5;
float sx = (2 - rr) / 2;
float sr = 0.5;


/***************************************** Déclaration formes gare *****************************************/
IndexedMesh* cube;
IndexedMesh* sphere;

void initAxes(){
	std::vector<float> points_x {0.0, 0.0, 0.0,
								10.0, 0.0, 0.0};
	std::vector<float> points_color_x {1.0, 0.0, 0.0,
								1.0, 0.0, 0.0};
	x.initSet(points_x,points_color_x);
	x.changeNature(GL_LINES);

	std::vector<float> points_y {0.0, 0.0, 0.0,
								0.0, 10.0, 0.0};
	std::vector<float> points_color_y {0.0, 1.0, 0.0,
										0.0, 1.0, 0.0};
	y.initSet(points_y,points_color_y);
	y.changeNature(GL_LINES);

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

void initRailCourbe(){
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

void initScene() {
	initAxes();
	initCylinder();

	cube = basicCube();
	cube->createVAO();
}

void drawCylindreFerme() {
	
	cercle.drawShape();
	cylinder->draw();

	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({ 0.0f, 1.f, 0.0f }); // Correction de la taille
		myEngine.updateMvMatrix();

		cercle.drawShape();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}

void drawRailDroit(){
	myEngine.setFlatColor(142.0/255,142.0/255,142.0/255);
	myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({ 0.0, 0.0, rr/2});
			myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({ 3.0, 5.0, rr});
			myEngine.updateMvMatrix();
				myEngine.mvMatrixStack.pushMatrix();
					myEngine.mvMatrixStack.addHomothety({ sr, 10.0, sr});
					myEngine.updateMvMatrix();
					cube->draw();
			
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({ 7.0, 5.0, rr});
			myEngine.updateMvMatrix();
				myEngine.mvMatrixStack.pushMatrix();
					myEngine.mvMatrixStack.addHomothety({ sr, 10.0, sr});
					myEngine.updateMvMatrix();
					cube->draw();
			
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	

	myEngine.setFlatColor(96.0/255,59.0/255,42.0/255);

	myEngine.mvMatrixStack.pushMatrix();
		Vector3D rt_1{0.0, 0.0, 1.0};
		myEngine.mvMatrixStack.addRotation(-M_PI/2, rt_1);
		myEngine.updateMvMatrix();



		myEngine.mvMatrixStack.addTranslation({ -(sx + rr/2) , 2.0, 0.0});
		myEngine.updateMvMatrix();

		myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();


		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addHomothety({rr/2, 6.0, rr/2});
			myEngine.updateMvMatrix();
				drawCylindreFerme();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();

		for (int i = 0; i < 4; i++)
		{
			myEngine.mvMatrixStack.addTranslation({ -(2*sx + rr) , 0.0, 0.0});
			myEngine.updateMvMatrix();

			myEngine.mvMatrixStack.pushMatrix();
				myEngine.mvMatrixStack.addHomothety({rr/2, 6.0, rr/2});
				myEngine.updateMvMatrix();
					drawCylindreFerme();
			myEngine.mvMatrixStack.popMatrix();
			myEngine.updateMvMatrix();
		}
		

		

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();


	
}

void drawRailCourbe(){

}



void axes(){
	x.drawSet();
	y.drawSet();
	z.drawSet();
}



void drawScene() {
	axes();
	drawRailDroit();
	
}




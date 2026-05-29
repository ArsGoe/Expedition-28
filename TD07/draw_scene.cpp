#include "draw_scene.hpp"

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
IndexedMesh* cube;
IndexedMesh* sphere;

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
	myEngine.updateMvMatrix();
}

void drawFenetre(){
	//Cylindre
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addHomothety({10.f, 1.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		drawCylindreFerme();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 

	//Rectangle
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.f, 0.5f, -13.f});
		myEngine.mvMatrixStack.addHomothety({20.f, 1.f, 25.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 

	//Cadre verticale
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, -7.5f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 35.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 

	//Cadre horizontal
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, 0.5f});
		myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 20.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 


	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, -8.5f});
		myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 20.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 

	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, -17.5f});
		myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 20.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 
}

void drawBatimentGare(){
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addHomothety({20.f, 15.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(124.0f/255.0f, 136.0f/255.0f, 132.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix(); 
}

void axes(){
	x.drawSet();
	y.drawSet();
	z.drawSet();
}

void drawScene() {
	axes();
	drawFenetre();
}




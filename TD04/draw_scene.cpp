#include "draw_scene.hpp"

/// Camera parameters
float angle_theta {45.0};      // Angle between x axis and viewpoint
float angle_phy {30.0};      // Angle between z axis and viewpoint
float dist_zoom {30.0};      // Distance between origin and viewpoint

GLBI_Engine myEngine;
GLBI_Set_Of_Points somePoints(3);
GLBI_Convex_2D_Shape ground{3};
GLBI_Convex_2D_Shape cercle{3};

//Mes variables
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};
IndexedMesh* sphere;
StandardMesh* cone;
float temps = 0.0f;

/********************************************************* AXES ***********************************************************/
void axes(){
	x.drawSet();
	y.drawSet();
	z.drawSet();
}

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

void initScene() {
	std::vector<float> points {0.0,0.0,0.0};
	somePoints.initSet(points,1.0,1.0,1.0);

	std::vector<float> baseCarre{-10.0,-10.0,0.0,
								 10.0,-10.0,0.0,
								 10.0,10.0,0.0,
								 -10.0,10.0,0.0};
	ground.initShape(baseCarre);
	ground.changeNature(GL_TRIANGLE_FAN);
	initAxes();
	//sphere = basicSphere();
	//sphere->createVAO();

	cone = basicCone(1.0f,1.0f);
	cone->createVAO();

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

void drawFrame() {
	// TO DO
}

void drawBase() {
	// TO DO
}

void drawArm() {
	// TO DO
}

void drawPan() {
	// TO DO
}

void drawScene() {
	temps += 1; //A chaque boucle de rendu, la variable augmente
	glPointSize(10.0);

	somePoints.drawSet();

	myEngine.setFlatColor(0.2,0.0,0.0);
	ground.drawShape();
	axes();

	/* myEngine.mvMatrixStack.pushMatrix();
		//En une ligne
		//myEngine.mvMatrixStack.addTranslation({4.f*cos(M_PI*temps/10.0f), 4.f*sin(M_PI*temps/10.0f), 5.f});

		//En plusieurs fois
		myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 5.f});
		myEngine.mvMatrixStack.addRotation(M_PI*temps/10.0f, {0.0,0.0,1.0});
		myEngine.mvMatrixStack.addTranslation({4.0f, 0.0f, 5.f});
		myEngine.mvMatrixStack.addHomothety(3.0);

		myEngine.updateMvMatrix();

		myEngine.setFlatColor(0.8,0.4,0.2);
		sphere->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.updateMvMatrix();  */

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0,0.0,0.1});
		myEngine.mvMatrixStack.addRotation(M_PI/2.0f, {1.0,0.0,0.0});
		myEngine.mvMatrixStack.addHomothety({2.0,10.0,2.0});
		myEngine.updateMvMatrix();

		myEngine.setFlatColor(0.8,0.4,0.2);
		cone->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0,0.0,0.1});
		myEngine.mvMatrixStack.addRotation(M_PI/2.0f, {1.0,0.0,0.0});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(0.0,1.0,0.0);
		cercle.drawShape();
	myEngine.mvMatrixStack.popMatrix();
}




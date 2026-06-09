#include "draw_scene.hpp"
#include "tools/basic_mesh.hpp"
#include "tools/gl_tools.hpp"
#include "tools/vector3d.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};	 // Angle between z axis and viewpoint
float dist_zoom{30.0};	 // Distance between origin and viewpoint

GLBI_Engine myEngine;

IndexedMesh *cylinder;
GLBI_Convex_2D_Shape cercle{3};

/***************************************** Variables des Rails *****************************************/
float rr = 0.5;
float sx = (2 - rr) / 2;
float sr = 0.5;

/***************************************** Premier Rail Courbe *****************************************/
GLBI_Convex_2D_Shape quart_de_cercle_debout1{3};
GLBI_Convex_2D_Shape quart_de_cercle_debout2{3};
GLBI_Convex_2D_Shape quart_de_cercle_allonge1{3};
GLBI_Convex_2D_Shape quart_de_cercle_allonge2{3};

/***************************************** Second Rail Courbe *****************************************/
GLBI_Convex_2D_Shape quart_de_cercle_debout3{3};
GLBI_Convex_2D_Shape quart_de_cercle_debout4{3};
GLBI_Convex_2D_Shape quart_de_cercle_allonge3{3};
GLBI_Convex_2D_Shape quart_de_cercle_allonge4{3};

GLBI_Convex_2D_Shape sides{3};
GLBI_Convex_2D_Shape sides_mais{3};

/***************************************** Axe XYZ *****************************************/
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};

/***************************************** Déclaration formes gare *****************************************/
IndexedMesh *cube;
IndexedMesh *sphere;

void initAxes()
{
	std::vector<float> points_x{0.0, 0.0, 0.0,
								10.0, 0.0, 0.0};
	std::vector<float> points_color_x{1.0, 0.0, 0.0,
									  1.0, 0.0, 0.0};
	x.initSet(points_x, points_color_x);
	x.changeNature(GL_LINES);

	std::vector<float> points_y{0.0, 0.0, 0.0,
								0.0, 10.0, 0.0};
	std::vector<float> points_color_y{0.0, 1.0, 0.0,
									  0.0, 1.0, 0.0};
	y.initSet(points_y, points_color_y);
	y.changeNature(GL_LINES);

	std::vector<float> points_z{0.0, 0.0, 0.0,
								0.0, 0.0, 10.0};
	std::vector<float> points_color_z{0.0, 0.0, 1.0,
									  0.0, 0.0, 1.0};
	z.initSet(points_z, points_color_z);
	z.changeNature(GL_LINES);
}

void initCylinder()
{
	cylinder = basicCylinder(1.0, 1.0);
	cylinder->createVAO();

	int nbPointDuCercle{100};
	int rayon{1};
	std::vector<float> initCercle{};
	for (int i{0}; i < nbPointDuCercle; i++)
	{
		float angle = 2 * M_PI * i / nbPointDuCercle;
		initCercle.push_back(sin(angle) * rayon);
		initCercle.push_back(0.0f);
		initCercle.push_back(cos(angle) * rayon);
	}

	cercle.initShape(initCercle);
	cercle.changeNature(GL_TRIANGLE_FAN);
}

void initFirstBentRail(float x, float size)
{
	int nbPointDuCercle{100};
	float rayon{size - rr/2};
	std::vector<float> initCercleDebout1{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleDebout1.push_back(sin(angle) * rayon);
		initCercleDebout1.push_back(cos(angle) * rayon);
		initCercleDebout1.push_back(0.0f);

		initCercleDebout1.push_back(sin(angle) * rayon);
		initCercleDebout1.push_back(cos(angle) * rayon);
		initCercleDebout1.push_back(x);
	}

	quart_de_cercle_debout1.initShape(initCercleDebout1);
	quart_de_cercle_debout1.changeNature(GL_TRIANGLE_STRIP);

	float rayon2{size + x - rr/2};
	std::vector<float> initCercleDebout2{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleDebout2.push_back(sin(angle) * rayon2);
		initCercleDebout2.push_back(cos(angle) * rayon2);
		initCercleDebout2.push_back(0.0f);

		initCercleDebout2.push_back(sin(angle) * rayon2);
		initCercleDebout2.push_back(cos(angle) * rayon2);
		initCercleDebout2.push_back(x);
	}

	quart_de_cercle_debout2.initShape(initCercleDebout2);
	quart_de_cercle_debout2.changeNature(GL_TRIANGLE_STRIP);

	std::vector<float> initCercleAllonge1{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleAllonge1.push_back(sin(angle) * rayon);
		initCercleAllonge1.push_back(cos(angle) * rayon);
		initCercleAllonge1.push_back(0.0f);

		initCercleAllonge1.push_back(sin(angle) * (rayon2));
		initCercleAllonge1.push_back(cos(angle) * (rayon2));
		initCercleAllonge1.push_back(0.0f);
	}

	quart_de_cercle_allonge1.initShape(initCercleAllonge1);
	quart_de_cercle_allonge1.changeNature(GL_TRIANGLE_STRIP);

	std::vector<float> initCercleAllonge2{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleAllonge2.push_back(sin(angle) * rayon);
		initCercleAllonge2.push_back(cos(angle) * rayon);
		initCercleAllonge2.push_back(x);

		initCercleAllonge2.push_back(sin(angle) * (rayon2));
		initCercleAllonge2.push_back(cos(angle) * (rayon2));
		initCercleAllonge2.push_back(x);
	}

	quart_de_cercle_allonge2.initShape(initCercleAllonge2);
	quart_de_cercle_allonge2.changeNature(GL_TRIANGLE_STRIP);
}

void initSecondBentRail(float x, float size)
{
	int nbPointDuCercle{100};
	float rayon{size - rr/2};
	std::vector<float> initCercleDebout3{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleDebout3.push_back(sin(angle) * rayon);
		initCercleDebout3.push_back(cos(angle) * rayon);
		initCercleDebout3.push_back(0.0f);

		initCercleDebout3.push_back(sin(angle) * rayon);
		initCercleDebout3.push_back(cos(angle) * rayon);
		initCercleDebout3.push_back(x);
	}

	quart_de_cercle_debout3.initShape(initCercleDebout3);
	quart_de_cercle_debout3.changeNature(GL_TRIANGLE_STRIP);

	float rayon2{size + x - rr/2};
	std::vector<float> initCercleDebout4{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleDebout4.push_back(sin(angle) * rayon2);
		initCercleDebout4.push_back(cos(angle) * rayon2);
		initCercleDebout4.push_back(0.0f);

		initCercleDebout4.push_back(sin(angle) * rayon2);
		initCercleDebout4.push_back(cos(angle) * rayon2);
		initCercleDebout4.push_back(x);
	}

	quart_de_cercle_debout4.initShape(initCercleDebout4);
	quart_de_cercle_debout4.changeNature(GL_TRIANGLE_STRIP);

	std::vector<float> initCercleAllonge3{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleAllonge3.push_back(sin(angle) * rayon);
		initCercleAllonge3.push_back(cos(angle) * rayon);
		initCercleAllonge3.push_back(0.0f);

		initCercleAllonge3.push_back(sin(angle) * (rayon2));
		initCercleAllonge3.push_back(cos(angle) * (rayon2));
		initCercleAllonge3.push_back(0.0f);
	}

	quart_de_cercle_allonge3.initShape(initCercleAllonge3);
	quart_de_cercle_allonge3.changeNature(GL_TRIANGLE_STRIP);

	std::vector<float> initCercleAllonge4{};
	for (int i{0}; i <= nbPointDuCercle; i++)
	{
		float angle = M_PI / 2 * i / nbPointDuCercle;
		initCercleAllonge4.push_back(sin(angle) * rayon);
		initCercleAllonge4.push_back(cos(angle) * rayon);
		initCercleAllonge4.push_back(x);

		initCercleAllonge4.push_back(sin(angle) * (rayon2));
		initCercleAllonge4.push_back(cos(angle) * (rayon2));
		initCercleAllonge4.push_back(x);
	}

	quart_de_cercle_allonge4.initShape(initCercleAllonge4);
	quart_de_cercle_allonge4.changeNature(GL_TRIANGLE_STRIP);
}

void initScene()
{
	initAxes();
	initCylinder();
	cube = basicCube();
	cube->createVAO();

	initFirstBentRail(sr, 3);
	initSecondBentRail(sr, 7);
}

void drawCylindreFerme()
{

	cercle.drawShape();
	cylinder->draw();

	myEngine.mvMatrixStack.pushMatrix();

	myEngine.mvMatrixStack.addTranslation({0.0f, 1.f, 0.0f}); // Correction de la taille
	myEngine.updateMvMatrix();

	cercle.drawShape();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
}

void drawRailDroit()
{
	// Couleur métal
	myEngine.setFlatColor(142.0 / 255, 142.0 / 255, 142.0 / 255);
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({0.0, 0.0, rr / 2});
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({3.0, 5.0, rr});
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addHomothety({sr, 10.0, sr});
	myEngine.updateMvMatrix();
	cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addTranslation({7.0, 5.0, rr});
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addHomothety({sr, 10.0, sr});
	myEngine.updateMvMatrix();
	cube->draw();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.setFlatColor(96.0 / 255, 59.0 / 255, 42.0 / 255);

	myEngine.mvMatrixStack.pushMatrix();
	Vector3D rt_1{0.0, 0.0, 1.0};
	myEngine.mvMatrixStack.addRotation(-M_PI / 2, rt_1);
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.addTranslation({-(sx + rr / 2), 2.0, 0.0});
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.pushMatrix();

	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	myEngine.mvMatrixStack.addHomothety({rr / 2, 6.0, rr / 2});
	myEngine.updateMvMatrix();
	drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();

	for (int i = 0; i < 4; i++)
	{
		myEngine.mvMatrixStack.addTranslation({-(2 * sx + rr), 0.0, 0.0});
		myEngine.updateMvMatrix();

		myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({rr / 2, 6.0, rr / 2});
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

void drawFirstBentRail()
{
	quart_de_cercle_allonge1.drawShape();
	quart_de_cercle_allonge2.drawShape();
	quart_de_cercle_debout1.drawShape();
	quart_de_cercle_debout2.drawShape();
}

void drawSecondBentRail()
{
	quart_de_cercle_allonge3.drawShape();
	quart_de_cercle_allonge4.drawShape();
	quart_de_cercle_debout3.drawShape();
	quart_de_cercle_debout4.drawShape();
}

void drawBentRail()
{
	// Couleur métal
	myEngine.setFlatColor(142.0 / 255, 142.0 / 255, 142.0 / 255);
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0, 0.0, rr});
		myEngine.updateMvMatrix();
			drawFirstBentRail();
			drawSecondBentRail();
	myEngine.mvMatrixStack.popMatrix();

	
	// Couleur bois
	myEngine.setFlatColor(96.0 / 255, 59.0 / 255, 42.0 / 255);

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0, 0.0, rr/2});
		myEngine.updateMvMatrix();
			Vector3D rotation{0.0, 0.0, 1.0};
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(-5*M_PI/12, rotation);
		myEngine.updateMvMatrix();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0, 2.0, 0.0});
			myEngine.updateMvMatrix();
				myEngine.mvMatrixStack.pushMatrix();
					myEngine.mvMatrixStack.addHomothety({rr / 2, 6.0, rr / 2});
					myEngine.updateMvMatrix();
						drawCylindreFerme();
				myEngine.mvMatrixStack.popMatrix();
			myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(-3*M_PI/12, rotation);
		myEngine.updateMvMatrix();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0, 2.0, 0.0});
			myEngine.updateMvMatrix();
				myEngine.mvMatrixStack.pushMatrix();
					myEngine.mvMatrixStack.addHomothety({rr / 2, 6.0, rr / 2});
					myEngine.updateMvMatrix();
						drawCylindreFerme();
				myEngine.mvMatrixStack.popMatrix();
			myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addRotation(-M_PI/12, rotation);
		myEngine.updateMvMatrix();
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0, 2.0, 0.0});
			myEngine.updateMvMatrix();
				myEngine.mvMatrixStack.pushMatrix();
					myEngine.mvMatrixStack.addHomothety({rr / 2, 6.0, rr / 2});
					myEngine.updateMvMatrix();
						drawCylindreFerme();
				myEngine.mvMatrixStack.popMatrix();
			myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	myEngine.mvMatrixStack.popMatrix();
	

	
}

void axes()
{
	x.drawSet();
	y.drawSet();
	z.drawSet();
}

void drawScene()
{
	axes();
	drawRailDroit();
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0, 10.0, 0.0});
		myEngine.updateMvMatrix();
			drawBentRail();
	myEngine.mvMatrixStack.popMatrix();
	myEngine.updateMvMatrix();
	
}

#include "draw_scene.hpp"
#include "tools/basic_mesh.hpp"
#include "tools/gl_tools.hpp"
#include "tools/vector3d.hpp"
#include "rails.hpp"

/// Camera parameters
float angle_theta{45.0}; // Angle between x axis and viewpoint
float angle_phy{30.0};	 // Angle between z axis and viewpoint
float dist_zoom{30.0};	 // Distance between origin and viewpoint

GLBI_Engine myEngine;

IndexedMesh *cylinder;
GLBI_Convex_2D_Shape cercle{3};

GLBI_Convex_2D_Shape sides{3};
GLBI_Convex_2D_Shape sides_mais{3};

/***************************************** Axe XYZ *****************************************/
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};

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

void initCube(){
	cube = basicCube(1.0f);
	cube->createVAO();
}

void initScene()
{
	initAxes();
	initCylinder();
	initCube();
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

#include "draw_scene.hpp"
#include "draw_gare_batiment.hpp"
#include "draw_train.hpp"
#include "texture.hpp"
#include "sol.hpp"
#include "light.hpp"
#include "rails.hpp"
#include "json_read.hpp"
#include "tools/basic_mesh.hpp"
#include "tools/gl_tools.hpp"
#include "tools/vector3d.hpp"


/// Caméra
float angle_theta {45.0};
float angle_phy {30.0};
float dist_zoom {30.0};
bool LightToPhongShading = false;

GLBI_Engine myEngine;

IndexedMesh* cylinder;
GLBI_Convex_2D_Shape cercleAvant{3};
GLBI_Convex_2D_Shape cercleArriere{3};
GLBI_Convex_2D_Shape cercle{3};

GLBI_Convex_2D_Shape sides{3};
GLBI_Convex_2D_Shape sides_mais{3};

/***************************************** Axe XYZ *****************************************/
GLBI_Set_Of_Points x{3};
GLBI_Set_Of_Points y{3};
GLBI_Set_Of_Points z{3};

/***************************************** Déclaration formes gare *****************************************/

void initAxes(){
	//X EN ROUGE
	std::vector<float> points_x {0.0, 0.0, 0.0,
								10.0, 0.0, 0.0};
	std::vector<float> points_color_x{1.0, 0.0, 0.0,
									  1.0, 0.0, 0.0};
	x.initSet(points_x, points_color_x);
	x.changeNature(GL_LINES);

	//Y EN VERT
	std::vector<float> points_y {0.0, 0.0, 0.0,
								0.0, 10.0, 0.0};
	std::vector<float> points_color_y{0.0, 1.0, 0.0,
									  0.0, 1.0, 0.0};
	y.initSet(points_y, points_color_y);
	y.changeNature(GL_LINES);

	//Z EN BLEU
	std::vector<float> points_z {0.0, 0.0, 0.0,
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

	int nbPointDuCercle { 100 };
	int rayon { 1 };
	std::vector<float> initCercle {};
	std::vector<float> cercleUVS {};
	for(int i { 0 }; i < nbPointDuCercle; i++) {
		float angle = 2 * M_PI * i / nbPointDuCercle;
		initCercle.push_back(sin(angle) * rayon);
		initCercle.push_back(0.0f);
		initCercle.push_back(cos(angle) * rayon);
		cercleUVS.push_back(0.5*cos(angle)+0.5);
		cercleUVS.push_back(0.5*sin(angle)+0.5);
	}
	cercleAvant.initShape(initCercle, cercleUVS, false);
    cercleAvant.changeNature(GL_TRIANGLE_FAN);

    cercleArriere.initShape(initCercle, cercleUVS, true); // normales {0, -1, 0}
    cercleArriere.changeNature(GL_TRIANGLE_FAN);
}

void initCube(){
	cube = basicCube(1.0f);
	cube->createVAO();
}

void initScene() {
	glActiveTexture(GL_TEXTURE0);
	initTexturesGare();
	initTexturesTrain();
	initTexturesSol();
	initTexturesMur();
	initAxes();
	initCylinder();
	initCube();
	initSphere();
	activeLight();
	initFirstBentRail(sr, 3);
	initSecondBentRail(sr, 7);
}

void drawCylindreFerme() {
    cercleAvant.drawShape();
    cylinder->draw();
    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({ 0.0f, 1.f, 0.0f });
        myEngine.updateMvMatrix();
        cercleArriere.drawShape();
    myEngine.mvMatrixStack.popMatrix();
}

void axes(){
	x.drawSet();
	y.drawSet();
	z.drawSet();
}

void drawScene(std::string file_name) {
	axes();
	if (LightToPhongShading) {
		myEngine.switchToPhongShading();
	}

	drawSol();
	drawMur();
	readJsonLoop(file_name);

	if (LightToPhongShading) {
		myEngine.switchToFlatShading();
	}
}

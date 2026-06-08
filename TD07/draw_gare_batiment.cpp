#include "draw_scene.hpp"
#include "draw_gare_batiment.hpp"
#include <vector>

IndexedMesh* cube = nullptr;
float temps = 0.0f;
/******************************** Texture *********************************/

struct GLBI_Texture murGare_texture;

/******************************** 3D *********************************/

void drawFenetre(){
	//Cylindre
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addHomothety({10.f, 1.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		drawCylindreFerme();

	myEngine.mvMatrixStack.popMatrix();

	//Rectangle
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.f, 0.5f, -13.f});
		myEngine.mvMatrixStack.addHomothety({20.f, 1.f, 25.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();

	//Cadre verticale
	myEngine.mvMatrixStack.pushMatrix();

		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, -7.5f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 35.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();

	myEngine.mvMatrixStack.popMatrix();

	//Cadre horizontal
	std::vector<Vector3D> positions = {
		{0.0f, 1.0f, 0.5f},
		{0.0f, 1.0f, -8.5f},
		{0.0f, 1.0f, -17.5f}
	};

	for (const auto& pos : positions){
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation(pos);
			myEngine.mvMatrixStack.addRotation(M_PI / 2, {0.f, 1.f, 0.f});
			myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 20.f});

			myEngine.updateMvMatrix();
			myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
			cube->draw();

		myEngine.mvMatrixStack.popMatrix();
	}
}

void drawBatimentGare(){
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({20.f, 15.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(124.0f/255.0f, 136.0f/255.0f, 132.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	//Cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, -7.5f, 5.f});
		myEngine.mvMatrixStack.addHomothety({3.f, 15.f, 3.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(124.0f/255.0f, 136.0f/255.0f, 132.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();
}

void drawPorte(){
	//Cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({10.f, 1.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(68.0f/255.0f, 62.0f/255.0f, 57.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	//Rectangle
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.5f, -13.f});
		myEngine.mvMatrixStack.addHomothety({20.f, 1.f, 25.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(68.0f/255.0f, 62.0f/255.0f, 57.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	//Cadre verticale
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, -7.5f});
		myEngine.mvMatrixStack.addHomothety({1.f, 1.f, 34.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(34.0f/255.0f, 38.0f/255.0f, 37.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	//Poignet
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({5.0f, 1.0f, -10.5f});
		myEngine.mvMatrixStack.addHomothety({1.f, 0.5f, 1.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(4.0f/255.0f, 38.0f/255.0f, 37.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-5.0f, 1.0f, -10.5f});
		myEngine.mvMatrixStack.addHomothety({1.f, 0.5f, 1.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(4.0f/255.0f, 38.0f/255.0f, 37.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();
}

void drawHorloge(){
	temps += 1;
	float angle = temps * (2.0f * -M_PI / 120.0f);
	float angle2 = temps * (2.0f * -M_PI / 1440.0f);
	
	//Cylindre
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({10.f, 1.f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	// Grande Aiguille
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, 0.0f});
		myEngine.mvMatrixStack.addRotation(angle, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 4.5f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 9.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(34.0f/255.0f, 38.0f/255.0f, 37.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	// Petite Aiguille
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f, 1.0f, 0.0f});
		myEngine.mvMatrixStack.addRotation(angle2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 3.5f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 7.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(34.0f/255.0f, 38.0f/255.0f, 37.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void drawBarriere(){
	std::vector<Vector3D> positions = {
		//Face
		{ 4.f, 0.f, 0.f },
		{ 2.f, 0.f, 0.f },
		{ 0.f, 0.f, 0.f },
		{ -2.f, 0.f, 0.f },
		{ -4.f, 0.f, 0.f },
	};

	for (size_t i = 0; i < positions.size(); ++i){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation(positions[i]);
			myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 5.f});

			myEngine.updateMvMatrix();
			myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
			cube->draw();
		myEngine.mvMatrixStack.popMatrix();
	}

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-6.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 7.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({6.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 7.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0., 0., 2.5f});
		myEngine.mvMatrixStack.addRotation(M_PI/2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 12.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void drawGare(){
	myEngine.mvMatrixStack.pushMatrix();
		drawBatimentGare();
	myEngine.mvMatrixStack.popMatrix();

	//Fenêtre
	std::vector<Vector3D> positionsFenetre = {
		//Face
		{ 7.0f, 7.5f, 2.0f },
		{ 4.0f, 7.5f, 2.0f },
		{ -7.0f, 7.5f, 2.0f },
		{ -4.0f, 7.5f, 2.0f },
		//Droite
		{ -10.0f, 5.5f, 2.0f },
		{ -10.0f, 2.75f, 2.0f },
		{ -10.0f, 0.0f, 2.0f },
		{ -10.0f, -2.75f, 2.0f },
		{ -10.0f, -5.5f, 2.0f },
		//Gauche
		{ 10.0f, 5.5f, 2.0f },
		{ 10.0f, 2.75f, 2.0f },
		{ 10.0f, 0.0f, 2.0f },
		{ 10.0f, -2.75f, 2.0f },
		{ 10.0f, -5.5f, 2.0f },
		//Dos
		{ -7.0f, -7.5f, 2.0f },
		{ -4.2f, -7.5f, 2.0f },
		{ -1.4f, -7.5f, 2.0f },
		{  1.4f, -7.5f, 2.0f },
		{  4.2f, -7.5f, 2.0f },
		{  7.0f, -7.5f, 2.0f }
	};

	std::vector<float> rotationFenetre = {
		0.0f, 0.0f, 0.0f, 0.0f, //Face
		M_PI/2, M_PI/2, M_PI/2, M_PI/2, M_PI/2, //Droite
		-M_PI/2, -M_PI/2, -M_PI/2, -M_PI/2, -M_PI/2, //Gauche
		M_PI, M_PI, M_PI, M_PI, M_PI, M_PI //Dos
	};

	for (size_t i = 0; i < positionsFenetre.size(); ++i){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation(positionsFenetre[i]);
			myEngine.mvMatrixStack.addRotation(rotationFenetre[i], {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addHomothety({0.10f, 0.10f, 0.10f});

			myEngine.updateMvMatrix();
			drawFenetre();
		myEngine.mvMatrixStack.popMatrix();
	}

	//Porte
	myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0f, 7.3f, 0.8f });
			myEngine.mvMatrixStack.addHomothety({0.20f, 0.40f, 0.22f});

			myEngine.updateMvMatrix();
			drawPorte();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation({0.0f, 7.5f, 5.5f });
			myEngine.mvMatrixStack.addHomothety({0.20f, 0.20f, 0.20f});

			myEngine.updateMvMatrix();
			drawHorloge();
	myEngine.mvMatrixStack.popMatrix();

	//Barrière
	std::vector<Vector3D> positionsBarriere = {
		//Face
		{ -8.5f, 7.5f, 5.2f },
		{ -5.5f, 7.5f, 5.2f },
		{  5.5f, 7.5f, 5.2f },
		{  8.5f, 7.5f, 5.2f },
		//Droite
		{ -10.0f,  5.65f, 5.2f },
		{ -10.0f,  1.9f, 5.2f },
		{ -10.0f, -1.9f, 5.2f },
		{ -10.0f, -5.65f, 5.2f },
		//Gauche
		{ 10.0f,  5.65f, 5.2f },
		{ 10.0f,  1.9f, 5.2f },
		{ 10.0f, -1.9f, 5.2f },
		{ 10.0f, -5.65f, 5.2f },
		//Dos
		{ -8.5f, -7.5f, 5.2f },
		{ -5.5f, -7.5f, 5.2f },
		{  5.5f, -7.5f, 5.2f },
		{  8.5f, -7.5f, 5.2f },
	};

	std::vector<float> rotationBarriere = {
		0.0f, 0.0f, 0.0f, 0.0f, //Face
		M_PI/2, M_PI/2, M_PI/2, M_PI/2, //Droite
		-M_PI/2, -M_PI/2, -M_PI/2, -M_PI/2, //Gauche
		M_PI, M_PI, M_PI, M_PI //Dos
	};

	for (size_t i = 0; i < positionsBarriere.size(); ++i){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation(positionsBarriere[i]);
			myEngine.mvMatrixStack.addRotation(rotationBarriere[i], {0.f, 0.f, 1.f});

			if (i < 4 || i > 11){
				myEngine.mvMatrixStack.addHomothety({0.25f, 0.5f, 0.10f});
			}
			else {
				myEngine.mvMatrixStack.addHomothety({0.32f, 0.29f, 0.10f});
			}

			myEngine.updateMvMatrix();
			drawBarriere();
		myEngine.mvMatrixStack.popMatrix();
	}

}
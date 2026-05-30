#include "draw_scene.hpp"
#include "draw_gare_batiment.hpp"
#include <vector>

IndexedMesh* cube = nullptr;
IndexedMesh* sphere = nullptr;

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
}

void drawGare(){
	myEngine.mvMatrixStack.pushMatrix();
		drawBatimentGare();
	myEngine.mvMatrixStack.popMatrix();

	//Fenêtre
	std::vector<Vector3D> positions = {
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

	std::vector<float> rotation = {
		0.0f, 0.0f, 0.0f, 0.0f, //Face
		M_PI/2, M_PI/2, M_PI/2, M_PI/2, M_PI/2, //Droite
		-M_PI/2, -M_PI/2, -M_PI/2, -M_PI/2, -M_PI/2, //Gauche
		M_PI, M_PI, M_PI, M_PI, M_PI, M_PI //Dos
	};

	for (size_t i = 0; i < positions.size(); ++i){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation(positions[i]);
			myEngine.mvMatrixStack.addRotation(rotation[i], {0.f, 0.f, 1.f});
			myEngine.mvMatrixStack.addHomothety({0.10f, 0.10f, 0.10f});
			drawFenetre();
		myEngine.mvMatrixStack.popMatrix();
		myEngine.updateMvMatrix();
	}
}
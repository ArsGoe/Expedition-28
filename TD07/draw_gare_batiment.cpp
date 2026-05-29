#include "draw_scene.hpp"
#include "draw_gare_batiment.hpp"

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
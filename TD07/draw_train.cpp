#include "draw_scene.hpp"
#include "draw_train.hpp"
#include <vector>

IndexedMesh* sphere = nullptr;
float temps2 = 0;
float tailleNuage = 0.5f;
float tempsNuage = 0;
float tailleNuage2 = 0.5f;
float tempsNuage2 = 2;

void initSphere(){
	sphere = basicSphere();
	sphere->createVAO();
}

void drawFenetreTrain(){
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({10.f, 0.5f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 0.3f, 0.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix(); 

    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 0.3f, 0.f});
        myEngine.mvMatrixStack.addRotation(M_PI/2, {0.f, 1.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 10.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix(); 
}

void drawCabine(){
    //Base
    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 3.5f});
		myEngine.mvMatrixStack.addHomothety({10.f, 10.f, 15.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

    //Fenêtres
    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({-5.f, 0.f, 6.f});
        myEngine.mvMatrixStack.addRotation(M_PI/2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addHomothety({0.7f, 0.7f, 0.7f});

		myEngine.updateMvMatrix();
		drawFenetreTrain();
	myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({5.f, 0.f, 6.f});
        myEngine.mvMatrixStack.addRotation(-M_PI/2, {0.f, 0.f, 1.f});
		myEngine.mvMatrixStack.addHomothety({0.7f, 0.7f, 0.7f});

		myEngine.updateMvMatrix();
		drawFenetreTrain();
	myEngine.mvMatrixStack.popMatrix();

    //Toit
    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 11.0f});
		myEngine.mvMatrixStack.addHomothety({12.f, 12.f, 0.5f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(163.0f/255.0f, 131.0f/255.0f, 122.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
        
    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 0.f, 11.5f});
		myEngine.mvMatrixStack.addHomothety({12.f, 8.f, 0.5f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(227.0f/255.0f, 195.0f/255.0f, 181.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void drawChemine(){
    myEngine.mvMatrixStack.pushMatrix();
	    myEngine.mvMatrixStack.addRotation(M_PI/2, {1.f, 0.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({3.f, 5.f, 3.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	    myEngine.mvMatrixStack.addRotation(M_PI/2, {1.f, 0.f, 0.f});
		myEngine.mvMatrixStack.addTranslation({0.f, 5.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({4.f, 1.f, 4.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();
}

void drawRoue(){
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({3.f, 0.5f, 3.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.1f, 0.0f});
		myEngine.mvMatrixStack.addHomothety({2.0f, 0.5f, 2.0f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(163.0f/255.0f, 131.0f/255.0f, 122.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.2f, 0.0f});
		myEngine.mvMatrixStack.addHomothety({1.0f, 0.5f, 1.0f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(101.0f/255.0f, 140.0f/255.0f, 136.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();
}

void drawBarre(){
		//Barre roue
	temps2 += 0.1f;
	float positionBarreY = 0.7 * sin(temps2);
	float positionBarreZ = 0.5 * cos(temps2);

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({5.5f, 1.5f, -4.5f});
    	myEngine.mvMatrixStack.addTranslation({0.0, positionBarreY, positionBarreZ});
		myEngine.mvMatrixStack.addHomothety({0.5f, 10.0f, 1.0f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(68.0f/255.0f, 62.0f/255.0f, 57.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-5.5f, 1.5f, -4.5f});
    	myEngine.mvMatrixStack.addTranslation({0.0, positionBarreY, positionBarreZ});
		myEngine.mvMatrixStack.addHomothety({0.5f, 10.0f, 1.0f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(68.0f/255.0f, 62.0f/255.0f, 57.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void drawNuage(){
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		sphere->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 1.5f, 2.f});
		myEngine.mvMatrixStack.addHomothety({1.5f, 1.5f, 1.5f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		sphere->draw();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 3.f, 0.f});
		myEngine.mvMatrixStack.addHomothety({2.5f, 2.5f, 2.5f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(168.0f/255.0f, 217.0f/255.0f, 217.0f/255.0f);
		sphere->draw();
	myEngine.mvMatrixStack.popMatrix();
}

void drawTrain(){

	//Base
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({5.f, 15.f, 5.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
	    myEngine.mvMatrixStack.addTranslation({0.f, 15.0f, 0.0f});
		myEngine.mvMatrixStack.addHomothety({3.f, 0.5f, 3.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(227.0f/255.0f, 195.0f/255.0f, 181.0f/255.0f);
		drawCylindreFerme();
	myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 5.0f, -3.5f});
		myEngine.mvMatrixStack.addHomothety({10.f, 20.f, 3.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

	//Cabine
    myEngine.mvMatrixStack.pushMatrix();
    	myEngine.updateMvMatrix();
        drawCabine();
    myEngine.mvMatrixStack.popMatrix();

    myEngine.mvMatrixStack.pushMatrix();
        myEngine.mvMatrixStack.addTranslation({0.f, 8.0f, 5.f});
        myEngine.mvMatrixStack.addHomothety({2.f, 2.f, 2.f});

        myEngine.updateMvMatrix();
        sphere->draw();
    myEngine.mvMatrixStack.popMatrix();

	//Cheminée
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 12.0f, 5.f});
		myEngine.mvMatrixStack.addHomothety({0.5f, 0.5f, 0.5f});

        myEngine.updateMvMatrix();
         drawChemine();
    myEngine.mvMatrixStack.popMatrix();

	//Roues
	std::vector<Vector3D> positionsRoues = {
		{-5.f, -2.f, -5.f},
		{-5.f, 5.f, -5.f},
		{5.f, -2.f, -5.f},
		{5.f, 5.f, -5.f},
		//Petite roue :
		{-5.f, 10.f, -5.9f},
		{-5.f, 14.f, -5.9f},
		{5.f, 10.f, -5.9f},
		{5.f, 14.f, -5.9f}
	};

	std::vector<float> rotationRoues = {
		M_PI/2, M_PI/2, -M_PI/2, -M_PI/2, //Grande roue
		M_PI/2, M_PI/2, -M_PI/2, -M_PI/2 //Petite roue
	};

	for (size_t i = 0; i < positionsRoues.size(); ++i){
		myEngine.mvMatrixStack.pushMatrix();
			myEngine.mvMatrixStack.addTranslation(positionsRoues[i]);
			myEngine.mvMatrixStack.addRotation(rotationRoues[i], {0.f, 0.f, 1.f});

			if (i > 3) {
				myEngine.mvMatrixStack.addHomothety({0.6f, 0.6f, 0.6f});
			}

			myEngine.updateMvMatrix();
			drawRoue();
		myEngine.mvMatrixStack.popMatrix();
	}

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.updateMvMatrix();
		drawBarre();
	myEngine.mvMatrixStack.popMatrix();

	//Avant
	myEngine.mvMatrixStack.pushMatrix();
    	myEngine.mvMatrixStack.addTranslation({0.f, 14.0f, -4.0f});
		myEngine.mvMatrixStack.addHomothety({9.8f, 3.0f, 2.f});

		myEngine.updateMvMatrix();
		myEngine.setFlatColor(163.0f/255.0f, 131.0f/255.0f, 122.0f/255.0f);
		cube->draw();
	myEngine.mvMatrixStack.popMatrix();

		//Nuage
	tailleNuage -= 0.01f;
	tempsNuage += 0.1f;
	tailleNuage2 -= 0.005f;
	tempsNuage2 += 0.1;

	if (tailleNuage <= 0.0f)
	{
		tailleNuage = 0.5f;
		tempsNuage = 0.0f;
			// générer un nouveau nuage
	}

	if (tailleNuage2 <= 0.0f)
	{
		tailleNuage2 = 0.7f;
		tempsNuage2 = 0.2f;
			// générer un nouveau nuage
	}
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 11.0f-tempsNuage, 8.f+tempsNuage});
		myEngine.mvMatrixStack.addHomothety({tailleNuage, tailleNuage, tailleNuage});

        myEngine.updateMvMatrix();
         drawNuage();
    myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.f, 0.0f, 1.0f});
		myEngine.mvMatrixStack.addTranslation({0.f, 11.0f-tempsNuage2, 8.f+tempsNuage2});
		myEngine.mvMatrixStack.addHomothety({tailleNuage2, tailleNuage2, tailleNuage2});

        myEngine.updateMvMatrix();
         drawNuage();
    myEngine.mvMatrixStack.popMatrix();

}
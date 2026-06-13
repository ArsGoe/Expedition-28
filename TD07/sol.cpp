#include "draw_scene.hpp"
#include "texture.hpp"

void drawSol(int size) {
    myEngine.mvMatrixStack.pushMatrix();
		//Pour que le sol soit au sol
		myEngine.mvMatrixStack.addTranslation({0.f, 0.f, -0.5f});
		myEngine.mvMatrixStack.addHomothety({10.f*size, 10.f*size, 1.f});

		myEngine.updateMvMatrix();
		//myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		myEngine.activateTexturing(true);
			herbeSol_texture.attachTexture();
				cube->draw();
			herbeSol_texture.detachTexture();
		myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();
}

void drawMur(int size) {
	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0,  size*10.0f/2, size*10.0f/2});
		//myEngine.mvMatrixStack.addRotation(-M_PI/2, {0.0f, 1.0f, 0.0f});
		myEngine.mvMatrixStack.addRotation(M_PI, {0.0f, 0.0f, 1.0f});

		myEngine.mvMatrixStack.addHomothety({10.0f*size, 2, 10.0f*size});

		myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
				mur1_texture.attachTexture();

					// myEngine.setFlatColor(0.f,1.f,0.f);
					cube->draw();
				mur1_texture.detachTexture();
			myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0, -size*10.0f/2, size*10.0f/2});
		myEngine.mvMatrixStack.addHomothety({10.0f*size, 2, 10.0f*size});

		myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
				mur2_texture.attachTexture();
					cube->draw();
				mur2_texture.detachTexture();
			myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({size*10.0f/2, 0, size*10.0f/2});
		myEngine.mvMatrixStack.addRotation(M_PI/2, {1.0f, 0.0f, 0.0f});
		myEngine.mvMatrixStack.addHomothety({2, 10.0f*size, 10.0f*size});

		myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
				mur3_texture.attachTexture();
					cube->draw();
				mur3_texture.detachTexture();
			myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({-size*10.0f/2, 0, size*10.0f/2});
		myEngine.mvMatrixStack.addRotation(M_PI/2, {1.0f, 0.0f, 0.0f});
		myEngine.mvMatrixStack.addHomothety({2, 10.0f*size, 10.0f*size});

		myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
				mur4_texture.attachTexture();
					cube->draw();
				mur4_texture.detachTexture();
			myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();

	myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addTranslation({0.0f, 0.0f, 10.0f*size});
		myEngine.mvMatrixStack.addHomothety({10.0f*size, 10.0f*size, 1.0f});

		myEngine.updateMvMatrix();

			myEngine.activateTexturing(true);
				ciel_texture.attachTexture();
					cube->draw();
				ciel_texture.detachTexture();
			myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();
}
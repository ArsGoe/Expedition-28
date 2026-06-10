#include "draw_scene.hpp"
#include "texture.hpp"

void drawSol() {
    myEngine.mvMatrixStack.pushMatrix();
		myEngine.mvMatrixStack.addHomothety({100.f, 100.f, 1.f});

		myEngine.updateMvMatrix();
		//myEngine.setFlatColor(178.0f/255.0f, 193.0f/255.0f, 187.0f/255.0f);
		myEngine.activateTexturing(true);
			herbeSol_texture.attachTexture();
				cube->draw();
			herbeSol_texture.detachTexture();
		myEngine.activateTexturing(false);
	myEngine.mvMatrixStack.popMatrix();

	for(int i = 0; i <= 10; i++){
		float x = -50.0f + i * 10.0f;
		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({x, 0.0f, 0.5f});
			myEngine.mvMatrixStack.addHomothety({0.2f, 100.0f, 0.1f});

			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.2f, 0.2f, 0.2f);
			cube->draw();

		myEngine.mvMatrixStack.popMatrix();
	}

	for(int i = 0; i <= 10; i++){
		float y = -50.0f + i * 10.0f;

		myEngine.mvMatrixStack.pushMatrix();

			myEngine.mvMatrixStack.addTranslation({0.0f, y, 0.5f});
			myEngine.mvMatrixStack.addHomothety({100.0f, 0.2f, 0.1f});

			myEngine.updateMvMatrix();
			myEngine.setFlatColor(0.2f, 0.2f, 0.2f);
			cube->draw();

		myEngine.mvMatrixStack.popMatrix();
	}
}
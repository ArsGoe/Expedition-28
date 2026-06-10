#include "draw_scene.hpp"
#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "tools/stb_image.h"

/********************************************** Herbe ********************************************************/

GLBI_Texture herbeSol_texture;

void initTexturesSol(){
    herbeSol_texture.createTexture();
	herbeSol_texture.attachTexture();
	herbeSol_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string herbeSol_image = "../TD07/assets/texture/herbeSol_Image.png";
	int x, y, n;
	unsigned char *imageHerbeSol = stbi_load(herbeSol_image.c_str(), &x, &y, &n, 0);
	if (imageHerbeSol == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		baseTrain_texture.loadImage(x, y, n, imageHerbeSol);
		stbi_image_free(imageHerbeSol);
	}

	herbeSol_texture.detachTexture();
}

/********************************************** Train ********************************************************/

GLBI_Texture baseTrain_texture;
GLBI_Texture nuageTrain_texture;
GLBI_Texture fenetreTrain_texture;

void initTexturesTrain(){
    baseTrain_texture.createTexture();
	baseTrain_texture.attachTexture();
	baseTrain_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string baseTrain_image = "../TD07/assets/texture/BaseTrain_Image.png";
	int x, y, n;
	unsigned char *imageBaseTrain = stbi_load(baseTrain_image.c_str(), &x, &y, &n, 0);
	if (imageBaseTrain == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		baseTrain_texture.loadImage(x, y, n, imageBaseTrain);
		stbi_image_free(imageBaseTrain);
	}

	baseTrain_texture.detachTexture();

	//Nuages
	nuageTrain_texture.createTexture();
	nuageTrain_texture.attachTexture();
	nuageTrain_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string nuageTrain_image = "../TD07/assets/texture/NuageTrain_Image.png";
	unsigned char *imageNuageTrain = stbi_load(nuageTrain_image.c_str(), &x, &y, &n, 0);
	if (imageNuageTrain == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		nuageTrain_texture.loadImage(x, y, n, imageNuageTrain);
		stbi_image_free(imageNuageTrain);
	}

	nuageTrain_texture.detachTexture();

	//Fenêtre
	fenetreTrain_texture.createTexture();
	fenetreTrain_texture.attachTexture();
	fenetreTrain_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string fenetreTrain_image = "../TD07/assets/texture/fenetreTrain_Image.png";
	unsigned char *imageFenetreTrain = stbi_load(fenetreTrain_image.c_str(), &x, &y, &n, 0);
	if (imageFenetreTrain == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		nuageTrain_texture.loadImage(x, y, n, imageFenetreTrain);
		stbi_image_free(imageFenetreTrain);
	}

	fenetreTrain_texture.detachTexture();
}

/************************************************ Gare **************************************************************/

GLBI_Texture murGare_texture;
GLBI_Texture fenetreGare_texture;
GLBI_Texture porteGare_texture;
GLBI_Texture horlogeGare_texture;

void initTexturesGare()
{
    murGare_texture.createTexture();
	murGare_texture.attachTexture();
	murGare_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string murGare_image = "../TD07/assets/texture/murGare_Image.png";
	int x, y, n;
	unsigned char *imageMurGare = stbi_load(murGare_image.c_str(), &x, &y, &n, 0);
	if (imageMurGare == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		murGare_texture.loadImage(x, y, n, imageMurGare);
		stbi_image_free(imageMurGare);
	}

	murGare_texture.detachTexture();

	//Fenêtre
	fenetreGare_texture.createTexture();
	fenetreGare_texture.attachTexture();
	fenetreGare_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string fenetreGare_image = "../TD07/assets/texture/FenetreGare_Image.png";
	unsigned char *fenetreGare = stbi_load(fenetreGare_image.c_str(), &x, &y, &n, 0);
	if (fenetreGare == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		fenetreGare_texture.loadImage(x, y, n, fenetreGare);
		stbi_image_free(fenetreGare);
	}

	fenetreGare_texture.detachTexture();

	//Porte
	porteGare_texture.createTexture();
	porteGare_texture.attachTexture();
	porteGare_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string porteGare_image = "../TD07/assets/texture/PorteGare_Image.png";
	unsigned char *porteGare = stbi_load(porteGare_image.c_str(), &x, &y, &n, 0);
	if (porteGare == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		porteGare_texture.loadImage(x, y, n, porteGare);
		stbi_image_free(porteGare);
	}

	porteGare_texture.detachTexture();

	//Horloge
	horlogeGare_texture.createTexture();
	horlogeGare_texture.attachTexture();
	horlogeGare_texture.setParameters(GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	std::string horlogeGare_image = "../TD07/assets/texture/HorlogeGare_Image.png";
	unsigned char *horlogeGare = stbi_load(horlogeGare_image.c_str(), &x, &y, &n, 0);
	if (horlogeGare == nullptr) {
		std::cout << "Image pas trouvé" << std::endl;
	}
	else {
		horlogeGare_texture.loadImage(x, y, n, horlogeGare);
		stbi_image_free(horlogeGare);
	}

	horlogeGare_texture.detachTexture();
}
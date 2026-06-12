#include "draw_scene.hpp"

void activeLight(){ 
    myEngine.switchToPhongShading();
    
    myEngine.setLightPosition({50.0f, 0.0f, 0.0f, 0.0},0); //On ajoute une ligne aux coordonnées X,Y,Z avec un vector, et on choisit c'est quelle light (ça sert à en foutre plusieurs)
    myEngine.setLightIntensity({0.5, 0.5, 0.5},0); // A quel point la light va être forte en vector et le numéro de la light
    myEngine.setShininess(12); // La brillance de la light

    myEngine.addALight({-50.0f, 0.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, -50.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, 50.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, 0.0f, 99.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, 0.0f, -99.0f, 0.0},{0.5, 0.5, 0.5});
    
    myEngine.switchToFlatShading();
}
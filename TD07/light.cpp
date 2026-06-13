#include "draw_scene.hpp"

void activeLight(){     
    //Eviter les faces noires
    myEngine.addALight({50.0f, 0.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({-50.0f, 0.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, -50.0f, 0.0f, 0.0},{1.0f, 0.8f, 0.5f});
    myEngine.addALight({0.0f, 50.0f, 0.0f, 0.0},{0.5, 0.5, 0.5});
    myEngine.addALight({0.0f, 0.0f, 99.0f, 0.0},{1.0f, 0.8f, 0.5f});
    myEngine.addALight({0.0f, 0.0f, -99.0f, 0.0},{0.5, 0.5, 0.5});
}
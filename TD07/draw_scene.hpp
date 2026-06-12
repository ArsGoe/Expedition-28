#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;

/* Camera parameters and functions */
static const float Z_NEAR {0.1f};
static const float Z_FAR {500.f};
extern float angle_theta;
extern float angle_phy;
extern float dist_zoom;
extern bool LightToPhongShading;
extern bool CercleArriere;

/* OpenGL Engine */
extern GLBI_Engine myEngine;

void initScene();

void drawFrame();

void drawBase();

void drawArm();

void drawPan();

void drawScene();

void initCylinder();

void initCube();

void drawCylindreFerme();

extern IndexedMesh* cube;
extern IndexedMesh* sphere;
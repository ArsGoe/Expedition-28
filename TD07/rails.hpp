#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;    // Distance between origin and viewpoint

/* OpenGL Engine */
extern GLBI_Engine myEngine;

/***************************************** Variables des Rails *****************************************/
extern float rr;
extern float sx;
extern float sr;

void initFirstBentRail(float x, float size);
void initSecondBentRail(float x, float size);

void drawRailDroit();
void drawFirstBentRail();
void drawSecondBentRail();
void drawBentRail();
#pragma once

#include "glbasimac/glbi_engine.hpp"
#include "glbasimac/glbi_set_of_points.hpp"
#include "glbasimac/glbi_convex_2D_shape.hpp"
#include "tools/basic_mesh.hpp"

using namespace glbasimac;    // Distance between origin and viewpoint

/* OpenGL Engine */
extern GLBI_Engine myEngine;
extern IndexedMesh* cube;
extern float temps;

void drawTrain();
void initSphere();